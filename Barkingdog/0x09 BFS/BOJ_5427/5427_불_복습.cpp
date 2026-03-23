#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

int n, m;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int bfs(const vector<vector<char> > &arr, vector<vector<int> > &visit, queue<tuple<int, int, bool> > &q) {
    while (!q.empty()) {
        const auto t = q.front();
        q.pop();
        bool dog = get<2>(t);

        for (int i = 0; i < 4; ++i) {
            int nx = get<0>(t) + dx[i];
            int ny = get<1>(t) + dy[i];

            if (nx < 0 || ny < 0 || nx >= n || ny >= m) {
                if (dog) return visit[get<0>(t)][get<1>(t)];
                continue;
            }

            if (visit[nx][ny] || arr[nx][ny] == '#') continue;
            visit[nx][ny] = visit[get<0>(t)][get<1>(t)] + 1;
            q.emplace(nx, ny, dog);
        }
    }

    return -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        cin >> m >> n;
        int srt_x, srt_y;
        vector<vector<char> > arr(n, vector<char>(m));
        vector<vector<int> > visit(n, vector<int>(m, 0));
        queue<tuple<int, int, bool> > q;

        for (int i = 0; i < n; ++i) {
            string s;
            cin >> s;
            for (int j = 0; j < m; ++j) {
                arr[i][j] = s[j];
                if (arr[i][j] == '@') {
                    srt_x = i;
                    srt_y = j;
                    visit[i][j] = 1;
                } else if (arr[i][j] == '*') {
                    q.emplace(i, j, false);
                    visit[i][j] = 1;
                }
            }
        }

        q.emplace(srt_x, srt_y, true);

        if (int ans = bfs(arr, visit, q); ans == -1) cout << "IMPOSSIBLE\n";
        else cout << ans << "\n";
    }

    return 0;
}
