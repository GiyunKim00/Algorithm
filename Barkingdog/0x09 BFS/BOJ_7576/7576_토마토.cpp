#include <iostream>
#include <queue>

using namespace std;

vector<vector<int>> arr(1001, vector<int>(1001, 0));
vector<vector<int>> visit(1001, vector<int>(1001, 0));
queue<pair<int, int>> q0;
int n, m;
int cnt = 0;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void bfs() {
    queue<pair<int, int>> q;
    while (!q0.empty()) {
        auto i = q0.front();
        visit[i.first][i.second] = 1;
        q.push(i);
        q0.pop();
    }

    while (!q.empty()) {
        pair<int, int> p = q.front();
        q.pop();

        for (int i = 0; i < 4; ++i) {
            int nx = p.first + dx[i];
            int ny = p.second + dy[i];

            if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
            if (visit[nx][ny] != 0) continue;

            visit[nx][ny] = visit[p.first][p.second] + 1;
            q.emplace(nx, ny);
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> m >> n;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            int t;
            cin >> t;
            arr[i][j] = t;
            if (t == 1) q0.emplace(i, j);
            if (t == -1) visit[i][j] = -1;
        }
    }

    bfs();

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (!visit[i][j]) {
                cout << "-1";
                return 0;
            }
            if (visit[i][j] != -1) cnt = max(cnt, visit[i][j]);
        }
    }

    cout << cnt - 1;

    return 0;
}