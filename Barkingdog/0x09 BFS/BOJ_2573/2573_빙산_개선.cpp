#include <iostream>
#include <queue>

using namespace std;

int N, M;
int arr[300][300];

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

void bfs(int x, int y, vector<vector<bool>> &visit) {
    queue<pair<int, int>> q;
    q.emplace(x, y);
    visit[x][y] = true;

    while (!q.empty()) {
        auto t = q.front();
        q.pop();
        for (int i = 0; i < 4; ++i) {
            int nx = t.first + dx[i];
            int ny = t.second + dy[i];

            if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
            if (visit[nx][ny]) continue;
            if (arr[nx][ny] > 0) {
                visit[nx][ny] = true;
                q.emplace(nx, ny);
            } else {
                arr[t.first][t.second]--;
                if (arr[t.first][t.second] <= 0) arr[t.first][t.second] = -1;
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
        vector<vector<bool>> visit(N, vector<bool>(M));
        ans++;

        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < M; ++j) {
                if (arr[i][j] > 0 && !visit[i][j]) {
                    cnt++;
                    if (cnt > 1) break;
                    bfs(i, j, visit);
                }
            }
            if (cnt > 1) break;
        }
        if (cnt != 1) break;


    }
    if (cnt > 1) cout << --ans;
    else cout << 0;

    return 0;
}