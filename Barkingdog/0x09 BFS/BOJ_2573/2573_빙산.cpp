#include <iostream>
#include <queue>

using namespace std;

int N, M;
int arr[300][300];

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

void bfs(int x, int y, vector<vector<bool>> &visit_water, vector<vector<bool>> &visit_land, bool mode) {
    queue<pair<int, int>> q;
    q.emplace(x, y);
    if(mode) visit_land[x][y] = true;
    else visit_water[x][y] = true;

    while (!q.empty()) {
        auto t = q.front();
        q.pop();
        for (int i = 0; i < 4; ++i) {
            int nx = t.first + dx[i];
            int ny = t.second + dy[i];

            if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
            if (mode) {
                if (visit_land[nx][ny] || !arr[nx][ny]) continue;
                visit_land[nx][ny] = true;
                q.emplace(nx, ny);
            } else {
                if (visit_water[nx][ny]) continue;
                if (arr[nx][ny] > 0) {
                    arr[nx][ny]--;
                    if (!arr[nx][ny]) arr[nx][ny] = -1;
                } else if (arr[nx][ny] != -1) {
                    visit_water[nx][ny] = true;
                    q.emplace(nx, ny);
                }
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int ans = 0, cnt = 0;
    cin >> N >> M;
    for (int i = 0; i < N; ++i) for (int j = 0; j < M; ++j) cin >> arr[i][j];

    while (true) {
        cnt = 0;
        vector<vector<bool>> visit_water(N, vector<bool>(M));
        vector<vector<bool>> visit_land(N, vector<bool>(M));
        ans++;
        for (int i = 0; i < N; ++i)
            for (int j = 0; j < M; ++j)
                if (arr[i][j] == 0 && !visit_water[i][j]) bfs(i, j, visit_water, visit_land, false);

        for (int i = 0; i < N; ++i)
            for (int j = 0; j < M; ++j)
                if (arr[i][j] == -1) arr[i][j] = 0;

        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < M; ++j) {
                if (arr[i][j] && !visit_land[i][j]) {
                    cnt++;
                    if (cnt > 1) break;
                    bfs(i, j, visit_water, visit_land, true);
                }
            }
            if (cnt > 1) break;
        }
        if (cnt != 1) break;
    }
    if (cnt > 1) cout << ans;
    else cout << 0;

    return 0;
}