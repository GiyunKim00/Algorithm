#include <iostream>
#include <queue>

using namespace std;
bool visit[100001];
int dx[3] = {-1, 1, 2};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N, K, cnt = 0;

    queue<pair<int, int>> q;
    cin >> N >> K;

    if (N == K) {
        cout << '0';
        return 0;
    } else if (N > K) {
        cout << N - K;
        return 0;
    }

    visit[N] = true;
    q.emplace(N, cnt);

    while (!q.empty()) {
        int g;
        auto t = q.front();
        q.pop();
//        cout << "now : " << t.first << ", cnt : " << t.second << "\n";
        if (t.first == 0) g = 1;
        else g = 0;

        for (int i = g; i < 3; ++i) {
            int nx;
            if (i == 0 || i == 1) nx = t.first + dx[i];
            else nx = t.first * dx[i];

            if (nx > 100000 || nx < 0) continue;
            if (visit[nx]) continue;
            if (nx == K) {
                cout << t.second + 1;
                return 0;
            } else {
                visit[nx] = true;
                q.emplace(nx, t.second + 1);
            }
        }
    }
}