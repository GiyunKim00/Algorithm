#include <iostream>
#include <queue>

using namespace std;

int arr[501][501];
bool visit[501][501];
int n, m;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int bfs(int x, int y) {
    int area = 1;
    queue<pair<int, int>> q;
    visit[x][y] = 1;

    q.emplace(x, y);

    while (!q.empty()) {
        pair<int, int> p = q.front();
        q.pop();

        for (int i = 0; i < 4; ++i) {
            int nx = p.first + dx[i];
            int ny = p.second + dy[i];

            if (nx < 0 || ny < 0 || nx > n || ny > m || visit[nx][ny] || arr[nx][ny] == 0) continue;
            q.emplace(nx, ny);
            visit[nx][ny] = true;
            area++;
        }
    }
    return area;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int max_area = 0, cnt = 0;

    cin >> n >> m;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            int t;
            cin >> t;
            arr[i][j] = t;
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (!visit[i][j] && arr[i][j] == 1) {
                cnt++;
                max_area = max(bfs(i, j), max_area);
            }
        }
    }

    cout << cnt << "\n" << max_area;

    return 0;
}