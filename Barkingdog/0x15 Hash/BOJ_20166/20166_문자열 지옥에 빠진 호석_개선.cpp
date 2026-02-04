#include <iostream>
#include <unordered_map>

using namespace std;

int n, m, k;
char arr[10][10];
unordered_map<string, int> ans;
int dx[8] = {0, 1, 0, -1, 1, 1, -1, -1};
int dy[8] = {1, 0, -1, 0, 1, -1, 1, -1};

void dfs(string &s, const int x, const int y) {
    ans[s]++;
    if (s.size() == 5) return;

    for (int i = 0; i < 8; ++i) {
        const int nx = (x + dx[i] + n) % n;
        const int ny = (y + dy[i] + m) % m;
        s.push_back(arr[nx][ny]);
        dfs(s, nx, ny);
        s.pop_back();
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ans.reserve(500000);
    string s;
    cin >> n >> m >> k;

    for (int i = 0; i < n; ++i) {
        cin >> s;
        for (int j = 0; j < m; ++j) arr[i][j] = s[j];
    }
    for (int a = 0; a < n; ++a) {
        for (int b = 0; b < m; ++b) {
            string tmp;
            tmp.push_back(arr[a][b]);
            dfs(tmp, a, b);
        }
    }

    for (int i = 0; i < k; ++i) {
        cin >> s;
        cout << ans[s] << "\n";
    }

    return 0;
}