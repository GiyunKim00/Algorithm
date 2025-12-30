#include <iostream>
#include <queue>

using namespace std;

int R, C;
char arr[1001][1001];
int visit[1001][1001];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};

queue<pair<int, int>> q;
queue<pair<int, int>> q0;

int bfs(int x, int y, bool human) {
    if (human) {
        visit[x][y] = 1;
        q.emplace(x, y);
    } else {
        while (!q0.empty()) {
            auto i = q0.front();
            q.push(i);
            visit[i.first][i.second] = 1;
            q0.pop();
        }
    }

    while (!q.empty()) {
        auto t = q.front();
        q.pop();

        for (int i = 0; i < 4; ++i) {
            int nx = t.first + dx[i];
            int ny = t.second + dy[i];

            if (nx < 0 || ny < 0 || nx >= C || ny >= R) {
                if (!human) continue;
                else return visit[t.first][t.second];
            }
            if (arr[nx][ny] == '#') continue;
            if (!human) {
                if (visit[nx][ny]) continue;
                visit[nx][ny] = visit[t.first][t.second] + 1;
                q.emplace(nx, ny);
            } else {
                if (visit[nx][ny] == 0 || visit[nx][ny] > visit[t.first][t.second] + 1) {
                    visit[nx][ny] = visit[t.first][t.second] + 1;
                    q.emplace(nx, ny);
                }
            }
        }
    }

    return false;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> C >> R;
    pair<int, int> fire, human;
    for (int i = 0; i < C; ++i) {
        string s;
        cin >> s;
        for (int j = 0; j < R; ++j) {
            arr[i][j] = s[j];
            if (s[j] == 'F') {
                fire = {i, j};
                q0.push(fire);
            }
            if (s[j] == 'J') human = {i, j};
        }
    }

    bfs(fire.first, fire.second, false);
    int ans = bfs(human.first, human.second, true);
    if (!ans) cout << "IMPOSSIBLE";
    else cout << ans;
}