#include <iostream>
#include <queue>

using namespace std;

int arr[101][101];
int N, max_height = 0;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void bfs(vector<vector<bool>> &visit, queue<pair<int, int>> *q, int level, int x, int y) {
    q->emplace(x, y);
    visit[x][y] = true;

    while (!q->empty()) {
        auto t = q->front();
        q->pop();

        for (int i = 0; i < 4; ++i) {
            int nx = t.first + dx[i];
            int ny = t.second + dy[i];

            if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
            if (arr[nx][ny] <= level || visit[nx][ny]) continue;

            q->emplace(nx, ny);
            visit[nx][ny] = true;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int max_cnt = 0;
    cin >> N;

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            int t;
            cin >> t;
            if (t > max_height) max_height = t;
            arr[i][j] = t;
        }
    }
    for (int k = 1; k < max_height; ++k) {
        vector<vector<bool>> visit(N, vector<bool>(N, 0));
        queue<pair<int, int>> q;
        int cnt = 0;
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                if (arr[i][j] > k && !visit[i][j]) {
                    cnt++;
                    bfs(visit, &q, k, i, j);
                }
            }
        }
        if(cnt > max_cnt) max_cnt = cnt;
    }
    if(max_cnt) cout << max_cnt;
    else cout << 1;

    return 0;
}