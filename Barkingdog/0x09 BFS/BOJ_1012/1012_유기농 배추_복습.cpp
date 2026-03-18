#include <iostream>
#include <queue>

using namespace std;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int n, m;

void bfs(const int x, const int y, const vector<vector<bool> > &arr, vector<vector<bool> > &visit) {
    queue<pair<int, int> > q;
    q.emplace(x, y);
    visit[x][y] = true;

    while (!q.empty()) {
        const auto [fst, snd] = q.front();
        q.pop();

        for (int i = 0; i < 4; ++i) {
            const int nx = fst + dx[i];
            const int ny = snd + dy[i];

            if (nx < 0 || ny < 0 || nx > n || ny > m) continue;
            if (!arr[nx][ny] || visit[nx][ny]) continue;
            q.emplace(nx, ny);
            visit[nx][ny] = true;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t, k;
    cin >> t;

    while (t--) {
        int cnt = 0;
        cin >> m >> n >> k;
        vector<vector<bool> > arr(n + 1, vector<bool>(m + 1, false));
        vector<vector<bool> > visit(n + 1, vector<bool>(m + 1, false));

        while (k--) {
            int x, y;
            cin >> y >> x;

            arr[x][y] = true;
        }

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (!visit[i][j] && arr[i][j]) {
                    bfs(i, j, arr, visit);
                    cnt++;
                }
            }
        }

        cout << cnt << "\n";
    }

    return 0;
}
