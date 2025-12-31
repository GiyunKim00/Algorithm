#include <iostream>
#include <queue>
#include <tuple>
#include <vector>

using namespace std;

int M, N, H;
int arr[101][101][101];
int visit[101][101][101];
queue<tuple<int, int, int>> q0;
queue<tuple<int, int, int>> q;

int dx[6] = {0, 1, 0, -1, 0, 0,};
int dy[6] = {1, 0, -1, 0, 0, 0};
int dz[6] = {0, 0, 0, 0, -1, 1};

void bfs() {
    while (!q0.empty()) {
        auto i = q0.front();
        q.push(i);
        visit[get<0>(i)][get<1>(i)][get<2>(i)] = 1;
        q0.pop();
    }

    while (!q.empty()) {
        auto t = q.front();
        q.pop();

        for (int i = 0; i < 6; ++i) {
            int nx = get<0>(t) + dx[i];
            int ny = get<1>(t) + dy[i];
            int nz = get<2>(t) + dz[i];

            if (nx < 0 || ny < 0 || nz < 0 || nx >= M || ny >= N || nz >= H) continue;
            if (arr[nx][ny][nz] == -1) continue;
            if (visit[nx][ny][nz]) continue;

            q.emplace(nx, ny, nz);
            visit[nx][ny][nz] = visit[get<0>(t)][get<1>(t)][get<2>(t)] + 1;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int max_cnt = 0;
    cin >> N >> M >> H;

    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < M; ++j) {
            for (int k = 0; k < N; ++k) {
                int t;
                cin >> t;
                if (t == 1) q0.emplace(j, k, i);
                arr[j][k][i] = t;
            }
        }
    }

    if (q0.empty()) {
        cout << "-1";
        return 0;
    }

    bfs();

    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < M; ++j) {
            for (int k = 0; k < N; ++k) {
                if (arr[j][k][i] != -1 && !visit[j][k][i]) {
                    cout << -1;
                    return 0;
                }
                max_cnt = max(max_cnt, visit[j][k][i]);
            }
        }
    }

    cout << max_cnt - 1;

    return 0;
}