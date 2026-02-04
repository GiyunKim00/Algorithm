#include <iostream>
#include <tuple>
#include <queue>

using namespace std;

int n, m, k;
string arr[10][10];
int dx[8] = {0, 1, 0, -1, 1, 1, -1, -1};
int dy[8] = {1, 0, -1, 0, 1, -1, 1, -1};

int bfs(string s, int x, int y) {
    int cnt = 0;
    queue<tuple<string, int, int> > q;
    const int len = s.size();
    q.emplace(arr[x][y], x, y);

    while (!q.empty()) {
        auto tmp = q.front();
        q.pop();
        int now_len = get<0>(tmp).size();
        if (now_len == len) {
            cnt++;
            continue;
        }
        for (int i = 0; i < 8; ++i) {
            int nx = (get<1>(tmp) + dx[i] + n) % n;
            int ny = (get<2>(tmp) + dy[i] + m) % m;

            if (string str = get<0>(tmp) + arr[nx][ny]; str[str.size() - 1] == s[str.size() - 1]) q.
                    emplace(str, nx, ny);
        }
    }

    return cnt;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> n >> m >> k;

    for (int i = 0; i < n; ++i) {
        cin >> s;
        for (int j = 0; j < m; ++j) arr[i][j] = s[j];
    }

    for (int i = 0; i<k; ++i) {
        int ans = 0;
        cin >> s;
        for (int a = 0; a < n; ++a) {
            for (int b = 0; b<m; ++b) if (arr[a][b][0] == s[0]) ans += bfs(s, a, b);
        }
        cout << ans << "\n";
    }

    return 0;
}