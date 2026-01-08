#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

int N, M, P;
int s[10];
int ans[10];
char arr[1000][1000];

queue<pair<int, int>> q[10];

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};


bool bfs(int x, int y, int player) {
    bool check = false;
    for (int i = 0; i < 4; ++i) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
        if (arr[nx][ny] != '.') continue;
        arr[nx][ny] = player + '0';
        ans[player]++;
        q[player].emplace(nx, ny);
        check = true;
    }

    return check;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> M >> P;
    for (int i = 1; i <= P; ++i) cin >> s[i];

    for (int i = 0; i < N; i++) {
        string str;
        cin >> str;
        for (int j = 0; j < M; ++j) {
            arr[i][j] = str[j];
            if (str[j] != '.' && str[j] != '#') {
                ans[str[j] - '0']++;
                q[str[j] - '0'].emplace(i, j);
            }
        }
    }

    while (true) {
        bool check = false;
        for (int i = 1; i <= P; ++i) {
            for (int j = 0; j < s[i]; ++j) {
                int qs = q[i].size();
                if (qs == 0) break;
                while(qs--) {
                    auto [x, y] = q[i].front();
                    q[i].pop();
                    if(bfs(x, y, i)) check = true;
                }
            }
        }
        if (!check) break;
    }

    for (int i = 1; i <= P; ++i)
        cout << ans[i] << " ";


    return 0;
}