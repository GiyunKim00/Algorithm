#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int M, N, K;

void bfs(vector<vector<int>> &arr, vector<vector<bool>> &visit, queue<pair<int, int>> *q, int x, int y) {
    q->emplace(x, y);
    visit[x][y] = true;

    while (!q->empty()) {

        auto t = q->front();
        q->pop();
//        cout << t.first << " " << t.second << "\n";

        for (int i = 0; i < 4; ++i) {
            int nx = t.first + dx[i];
            int ny = t.second + dy[i];

            if (nx < 0 || ny < 0 || nx >= M || ny >= N) continue;
            if (visit[nx][ny] || arr[nx][ny] != 1) continue;

            visit[nx][ny] = true;
            q->emplace(nx, ny);
        }

    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin >> T;

    while (T--) {
        int cnt = 0;
        cin >> N >> M >> K;

        vector<vector<int>> arr(M, vector<int>(N, 0));
        vector<vector<bool>> visit(M, vector<bool>(N, false));
        queue<pair<int, int>> q;

        for (int i = 0; i < K; ++i) {
            int a, b;
            cin >> b >> a;
            arr[a][b] = 1;
        }

        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                if (arr[i][j] == 1 && !visit[i][j]) {
                    cnt++;
                    bfs(arr, visit, &q, i, j);
                }
            }
        }
        cout << cnt << "\n";
    }

    return 0;
}