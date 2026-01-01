#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

int N, M;
int arr[1000][1000];
int visit[1000][1000][2];

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int bfs() {

    queue<tuple<int, int, int>> q;
    q.emplace(0, 0, 0);
    visit[0][0][0] = 1;

    while (!q.empty()) {
        auto t = q.front();
        q.pop();
        for (int i = 0; i < 4; ++i) {
            int nx = get<0>(t) + dx[i];
            int ny = get<1>(t) + dy[i];
            int crash = get<2>(t);

            if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
            if (visit[nx][ny][crash]) continue;
            if (nx == N - 1 && ny == M - 1) return visit[get<0>(t)][get<1>(t)][crash] + 1;
            if (!arr[nx][ny]) {
                visit[nx][ny][crash] = visit[get<0>(t)][get<1>(t)][crash] + 1;
                q.emplace(nx, ny, crash);
            } else {
                if (!crash) {
                    visit[nx][ny][1] = visit[get<0>(t)][get<1>(t)][crash] + 1;
                    q.emplace(nx, ny, 1);
                }
            }
        }
    }

    return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> M;
    if (!N && !M) cout << 0;
    else if (N == 1 && M == 1) cout << 1;
    else {
        for (int i = 0; i < N; ++i) {
            string s;
            cin >> s;
            for (int j = 0; j < M; ++j)arr[i][j] = s[j] - '0';
        }

        int ans = bfs();
        if (ans) cout << ans;
        else cout << -1;
    }

    return 0;
}