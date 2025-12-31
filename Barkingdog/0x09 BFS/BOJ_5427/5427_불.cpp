#include <iostream>
#include <queue>

using namespace std;

int w, h;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};


int bfs(int x, int y, bool dog, vector<vector<char>> &arr, vector<vector<int>> &visit, queue<pair<int, int>> *q, queue<pair<int, int>> *q0) {
    if (dog) {
        visit[x][y] = 1;
        q->emplace(x, y);
    } else {
        while (!q0->empty()) {
            auto i = q0->front();
            q->push(i);
            visit[i.first][i.second] = 1;
            q0->pop();
        }
    }

    while (!q->empty()) {
        auto t = q->front();
        q->pop();

        for (int i = 0; i < 4; ++i) {
            int nx = t.first + dx[i];
            int ny = t.second + dy[i];

            if (nx < 0 || ny < 0 || nx >= w || ny >= h) {
                if (!dog) continue;
                else return visit[t.first][t.second];
            }
            if (arr[nx][ny] == '#') continue;
            if (!dog) {
                if (visit[nx][ny]) continue;
                visit[nx][ny] = visit[t.first][t.second] + 1;
                q->emplace(nx, ny);
            } else {
                if (visit[nx][ny] == 0 || visit[nx][ny] > visit[t.first][t.second] + 1) {
                    visit[nx][ny] = visit[t.first][t.second] + 1;
                    q->emplace(nx, ny);
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
    int N;
    cin >> N;

    while(N--) {
        cin >> h >> w;
        vector<vector<char>> arr(w, vector<char>(h, 0));
        vector<vector<int>> visit(w, vector<int>(h, 0));

        queue<pair<int, int>> q;
        queue<pair<int, int>> q0;
        pair<int, int> fire, dog;
        for (int i = 0; i < w; ++i) {
            string s;
            cin >> s;
            for (int j = 0; j < h; ++j) {
                arr[i][j] = s[j];
                if (s[j] == '*') {
                    fire = {i, j};
                    q0.push(fire);
                }
                if (s[j] == '@') dog = {i, j};
            }
        }

        bfs(fire.first, fire.second, false, arr, visit, &q, &q0);
        int ans = bfs(dog.first, dog.second, true, arr, visit, &q, &q0);
        if (!ans) cout << "IMPOSSIBLE\n";
        else cout << ans << "\n";
    }

    return 0;
}