#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

int N, K;
bool visit[500003][2];

int bfs() {
    queue<pair<int, int>> q;
    q.emplace(N, 0);
    visit[N][0] = true;

    while (!q.empty()) {
        auto [x, t] = q.front();
        q.pop();

        int bro = K + t * (t + 1) / 2;
        if (bro > 500000) return -1;

        if (visit[bro][t % 2]) return t;

        for (int nx : {x - 1, x + 1, 2 * x}) {
            if (nx < 0 || nx > 500000) continue;
            if (visit[nx][(t + 1) % 2]) continue;

            visit[nx][(t + 1) % 2] = true;
            q.emplace(nx, t + 1);
        }
    }

    return -1;
}

int main() {
    cin >> N >> K;
    if (N == K) cout << 0;
    else cout << bfs();

    return 0;
}