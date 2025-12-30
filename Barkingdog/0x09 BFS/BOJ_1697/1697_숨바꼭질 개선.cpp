#include <iostream>
#include <queue>

using namespace std;
bool visit[100001];

int bfs(int n, int k) {
    queue<pair<int, int>> q;
    q.emplace(n, 0);
    visit[n] = true;

    while (!q.empty()) {
        auto t = q.front();
        if (t.first == k) return t.second;
        q.pop();
//        cout << "now : " << t.first << ", cnt : " << t.second << "\n";

        for (int i: {t.first - 1, t.first + 1, 2 * t.first}) {
            if (i > 100000 || i < 0 || visit[i]) continue;

            visit[i] = true;
            q.emplace(i, t.second + 1);
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N, K;
    cin >> N >> K;

    if (N == K) cout << '0';
    else if (N > K) cout << N - K;
    else cout << bfs(N, K);

    return 0;
}