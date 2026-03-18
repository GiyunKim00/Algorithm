#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

int n, m, h;
int dx[6] = {0, 1, 0, -1, 0, 0};
int dy[6] = {1, 0, -1, 0, 0, 0};
int dz[6] = {0, 0, 0, 0, 1, -1};

int arr[100][100][100];
int visit[100][100][100];
queue<tuple<int, int, int> > q;

void bfs() {
    while (!q.empty()) {
        const auto t = q.front();
        q.pop();

        for (int i = 0; i < 6; ++i) {
            const int nx = get<0>(t) + dx[i];
            const int ny = get<1>(t) + dy[i];
            const int nz = get<2>(t) + dz[i];

            if (nx < 0 || ny < 0 || nz < 0 || nx >= n || ny >= m || nz >= h) continue;
            if (arr[nx][ny][nz] != 0) continue;
            if (visit[nx][ny][nz] == 0 || (visit[nx][ny][nz] > 0 && visit[nx][ny][nz] > visit[get<0>(t)][get<1>(t)][get<
                                               2>(t)] + 1)) {
                q.emplace(nx, ny, nz);
                visit[nx][ny][nz] = visit[get<0>(t)][get<1>(t)][get<2>(t)] + 1;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int ans = 0;
    bool check = false;

    cin >> m >> n >> h;
    for (int k = 0; k < h; ++k)
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j) {
                cin >> arr[i][j][k];
                if (arr[i][j][k] == -1) visit[i][j][k] = -1;
                if (arr[i][j][k] == 0) check = true;
                if (arr[i][j][k] == 1) {
                    q.emplace(i, j, k);
                    visit[i][j][k] = 1;
                }
            }

    if (!check) {
        cout << 0;
        return 0;
    }

    bfs();

    for (int k = 0; k < h; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (arr[i][j][k] == -1) continue;
                if (visit[i][j][k] == 0) {
                    cout << -1;
                    return 0;
                }
                ans = max(ans, visit[i][j][k]);
            }
        }
    }

    cout << ans - 1;
    return 0;
}
