#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;

int N, X;
int visit[200001];

int bfs() {
    deque<int> q;
    q.push_front(N);
    visit[N] = 1;

    while (!q.empty()) {
        auto t = q.front();
        q.pop_front();
        if (t == X) return visit[t] - 1;

        int nx = 2 * t;
        if (nx >= 0 && nx <= 100000) {
            if (!visit[nx] || visit[nx] > visit[t]) {
                visit[nx] = visit[t];
                q.push_front(nx);
            }
        }

        for (int next: {t + 1, t - 1}) {
            if (next < 0 || next > 100000) continue;
            if (!visit[next] || visit[next] > visit[t] + 1) {
                visit[next] = visit[t] + 1;
                q.push_back(next);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> X;

    if (X < N) cout << N - X;
    else if (N == X) cout << 0;
    else cout << bfs();

    return 0;
}