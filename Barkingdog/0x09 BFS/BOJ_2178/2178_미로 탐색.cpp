#include <iostream>
#include <queue>

using namespace std;

int arr[101][101];
int visit[101][101];
int n, m;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int bfs(int x, int y) {
    queue<pair<int, int>> q;
    visit[x][y] = 1;
    q.emplace(x, y);

    while (!q.empty()) {
        pair<int, int> p = q.front();
        q.pop();
        if (p.first == n - 1 && p.second == m - 1) return visit[p.first][p.second];

        for (int i = 0; i < 4; ++i) {
            int nx = p.first + dx[i];
            int ny = p.second + dy[i];
            if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
            if (arr[nx][ny] == 0) continue;
            if (visit[nx][ny] != 0) continue;
            q.emplace(nx, ny);
            visit[nx][ny] = visit[p.first][p.second] + 1;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        for (int j = 0; j < m; ++j) {
            arr[i][j] = s[j] - '0';
        }
    }
    int cnt = bfs(0, 0);
    cout << cnt;

    return 0;
}