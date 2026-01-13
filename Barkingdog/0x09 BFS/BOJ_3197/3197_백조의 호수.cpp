#include <iostream>
#include <queue>
#include <cstring>

using namespace std;
int R, C, ans = 0;
char arr[1501][1501];
int visit[1501][1501];
int visit_swan[1501][1501];
queue<pair<int, int>> melt;
pair<int, int> swan_1 = {-1, -1}, swan_2;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

bool swan_bfs() {
    queue<pair<int, int>> q;
    q.emplace(swan_1.first, swan_1.second);
    visit_swan[swan_1.first][swan_1.second] = true;

    while (!q.empty()) {
        auto t = q.front();
        q.pop();

        if (t.first == swan_2.first && t.second == swan_2.second) return true;

        for (int i = 0; i < 4; ++i) {
            int nx = t.first + dx[i];
            int ny = t.second + dy[i];

            if (nx < 0 || ny < 0 || nx >= R || ny >= C) continue;
            if (visit_swan[nx][ny] || arr[nx][ny] == 'X') continue;

            q.emplace(nx, ny);
            visit_swan[nx][ny] = true;
        }
    }

    return false;
}

void bfs(int x, int y) {
    queue<pair<int, int>> q;
    q.emplace(x, y);
    visit[x][y] = ans;

    while (!q.empty()) {
        bool check = false;
        auto t = q.front();
        q.pop();

        for (int i = 0; i < 4; ++i) {
            int nx = t.first + dx[i];
            int ny = t.second + dy[i];

            if (nx < 0 || ny < 0 || nx >= R || ny >= C) continue;
            if (visit[nx][ny] == ans) continue;
            if (arr[nx][ny] == '.' || arr[nx][ny] == 'L') {
                check = true;
                continue;
            }
            visit[nx][ny] = ans;
            q.emplace(nx, ny);
        }
        if (check) melt.emplace(t.first, t.second);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> R >> C;

    for (int i = 0; i < R; ++i) {
        string s;
        cin >> s;
        for (int j = 0; j < C; ++j) {
            arr[i][j] = s[j];
            if (s[j] == 'L') {
                if (swan_1.first == -1) swan_1 = {i, j};
                else swan_2 = {i, j};
            }
        }
    }


    if (swan_bfs()) {
        cout << 0;
        return 0;
    }

    while (true) {
        ans++;
        for (int i = 0; i < R; ++i) {
            for (int j = 0; j < C; ++j) {
                if (arr[i][j] == 'X' && visit[i][j] != ans) bfs(i, j);
            }
        }

        while (!melt.empty()) {
            auto t = melt.front();
            arr[t.first][t.second] = '.';
            melt.pop();
        }
        memset(visit_swan, 0, sizeof(visit_swan));

//        for (int i = 0; i < R; ++i) {
//            for (int j = 0; j < C; ++j) {
//                cout << arr[i][j] << " ";
//            }
//            cout <<"\n";
//        }
//        cout <<"\n";

        if (swan_bfs()) break;
    }

    cout << ans;

    return 0;
}