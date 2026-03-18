#include <iostream>
#include <queue>

using namespace std;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int n;
char arr[100][100];

int color_code(const char c) {
    if (c == 'B') return 0;
    return 1;
}

void bfs(const int x, const int y, vector<vector<bool> > &visit, const int mode) {
    queue<pair<int, int> > q;
    q.emplace(x, y);
    visit[x][y] = true;

    while (!q.empty()) {
        const auto [fst, snd] = q.front();
        q.pop();

        for (int i = 0; i < 4; ++i) {
            int nx = fst + dx[i];
            int ny = snd + dy[i];

            if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
            if (visit[nx][ny]) continue;
            if (!mode) {
                if (arr[x][y] != arr[nx][ny]) continue;
            } else {
                if (color_code(arr[x][y]) != color_code(arr[nx][ny])) continue;
            }
            q.emplace(nx, ny);
            visit[nx][ny] = true;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        for (int j = 0; j < n; ++j) arr[i][j] = s[j];
    }

    for (int k = 0; k < 2; ++k) {
        int cnt = 0;
        vector<vector<bool> > visit(n, vector<bool>(n, false));

        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                if (!visit[i][j]) {
                    bfs(i, j, visit, k);
                    cnt++;
                }
        cout << cnt << " ";
    }

    return 0;
}
