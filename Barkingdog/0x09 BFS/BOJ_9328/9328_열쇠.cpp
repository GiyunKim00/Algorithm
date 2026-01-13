#include <iostream>
#include <queue>

using namespace std;

int h, w;
bool alphabet[26];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

void
bfs(int x, int y, vector<vector<char>> &arr, vector<vector<bool>> &visit, queue<pair<int, int>> capital[26], int &ans) {
    queue<pair<int, int>> q;
    q.emplace(x, y);
    visit[x][y] = true;

    while (!q.empty()) {
        auto t = q.front();
        q.pop();
        if (arr[t.first][t.second] == '$') ans++;
        if (arr[t.first][t.second] >= 'a' && arr[t.first][t.second] <= 'z') {
            alphabet[arr[t.first][t.second] - 'a'] = true;
            while (!capital[toupper(arr[t.first][t.second]) - 'A'].empty()) {
                auto k = capital[toupper(arr[t.first][t.second]) - 'A'].front();
                capital[toupper(arr[t.first][t.second]) - 'A'].pop();
                for (int j = 0; j < 4; ++j) {
                    int next_x = k.first + dx[j];
                    int next_y = k.second + dy[j];
                    if (next_x < 0 || next_y < 0 || next_x >= h || next_y >= w) {
                        q.emplace(k.first, k.second);
                        arr[k.first][k.second] = '.';
                        visit[k.first][k.second] = true;
                        break;
                    }
                    if (visit[next_x][next_y]) {
                        q.emplace(k.first, k.second);
                        arr[k.first][k.second] = '.';
                        visit[k.first][k.second] = true;
                        break;
                    }
                }
            }
            arr[t.first][t.second] = '.';
        }

        for (int i = 0; i < 4; ++i) {
            int nx = t.first + dx[i];
            int ny = t.second + dy[i];

            if (nx < 0 || ny < 0 || nx >= h || ny >= w) continue;
            if (visit[nx][ny] || arr[nx][ny] == '*') continue;
            if ((arr[nx][ny] >= 'A' && arr[nx][ny] <= 'Z') && !alphabet[arr[nx][ny] - 'A']) continue;
            if (arr[nx][ny] >= 'A' && arr[nx][ny] <= 'Z') arr[nx][ny] = '.';
            visit[nx][ny] = true;
            q.emplace(nx, ny);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int test_case;
    string key;
    cin >> test_case;

    while (test_case--) {
        queue<pair<int, int>> q;
        queue<pair<int, int>> capital[26];
        int ans = 0;

        cin >> h >> w;
        vector<vector<char>> arr(h, vector<char>(w));
        vector<vector<bool>> visit(h, vector<bool>(w, false));

        for (int i = 0; i < h; ++i) {
            string s;
            cin >> s;
            for (int j = 0; j < w; ++j) {
                if (s[j] >= 'A' && s[j] <= 'Z') capital[s[j] - 'A'].emplace(i, j);
                arr[i][j] = s[j];
            }

        }

        cin >> key;
        if (key != "0") for (auto i: key) alphabet[i - 'a'] = true;

        for (int i = 1; i < h - 1; i++) {
            if (
                    arr[i][0] == '.' ||
                    arr[i][0] == '$' ||
                    (arr[i][0] >= 'A' && arr[i][0] <= 'Z' && alphabet[arr[i][0] - 'A']) ||
                    (arr[i][0] >= 'a' && arr[i][0] <= 'z')
                    )
                q.emplace(i, 0);
            if (arr[i][w - 1] == '.' || arr[i][w - 1] == '$' ||
                (arr[i][w - 1] >= 'A' && arr[i][w - 1] <= 'Z' && alphabet[arr[i][w - 1] - 'A']) ||
                (arr[i][w - 1] >= 'a' && arr[i][w - 1] <= 'z'))
                q.emplace(i, w - 1);

        }

        for (int j = 0; j < w; j++) {
            if (arr[0][j] == '.' || arr[0][j] == '$' ||
                (arr[0][j] >= 'A' && arr[0][j] <= 'Z' && alphabet[arr[0][j] - 'A']) ||
                (arr[0][j] >= 'a' && arr[0][j] <= 'z'))
                q.emplace(0, j);
            if (arr[h - 1][j] == '.' || arr[h - 1][j] == '$' ||
                (arr[h - 1][j] >= 'A' && arr[h - 1][j] <= 'Z' && alphabet[arr[h - 1][j] - 'A']) ||
                (arr[h - 1][j] >= 'a' && arr[h - 1][j] <= 'z'))
                q.emplace(h - 1, j);
        }

        while (!q.empty()) {
            auto t = q.front();
            q.pop();
            if (visit[t.first][t.second]) continue;
            bfs(t.first, t.second, arr, visit, capital, ans);
        }

//        for (int i = 0; i < h; ++i) {
//            for (int j = 0; j < w; ++j) {
//                cout << arr[i][j] << " ";
//            }
//            cout << "\n";
//        }

        for (bool &i: alphabet) i = false;
        cout << ans << "\n";
    }
}