#include <iostream>
#include <queue>
#include <tuple>

using namespace std;
int R, C, ans = 0;
char arr[1501][1501];
bool visit[1501][1501];
int visit_swan[1501][1501];
queue<tuple<int, int, int>> water;
queue<pair<int, int>> land[3006];
queue<pair<int, int>> swan_q;
queue<pair<int, int>> swan_next;
pair<int, int> swan_1 = {-1, -1}, swan_2;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

bool swan_bfs() {
    while (!swan_q.empty()) {
        auto t = swan_q.front();
        swan_q.pop();

        if (t.first == swan_2.first && t.second == swan_2.second)
            return true;

        for (int i = 0; i < 4; ++i) {
            int nx = t.first + dx[i];
            int ny = t.second + dy[i];

            if (nx < 0 || ny < 0 || nx >= R || ny >= C) continue;
            if (visit_swan[nx][ny]) continue;

            visit_swan[nx][ny] = true;

            if (arr[nx][ny] == 'X') swan_next.emplace(nx, ny);
            else swan_q.emplace(nx, ny);
        }
    }
    return false;
}

void bfs() {
    while (!water.empty()) {
        auto t = water.front();
        water.pop();

        for (int i = 0; i < 4; ++i) {
            int nx = get<0>(t) + dx[i];
            int ny = get<1>(t) + dy[i];

            if (nx < 0 || ny < 0 || nx >= R || ny >= C) continue;
            if (visit[nx][ny]) continue;

            visit[nx][ny] = true;

            if (arr[nx][ny] == 'X') {
                land[get<2>(t) + 1].emplace(nx, ny);
                water.emplace(nx, ny, get<2>(t) + 1);
            } else water.emplace(nx, ny, get<2>(t));
        }
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
            if (s[j] != 'X') {
                water.emplace(i, j, 0);
                visit[i][j] = true;
            }
        }
    }

    swan_q.emplace(swan_1.first, swan_1.second);
    visit_swan[swan_1.first][swan_1.second] = true;

    if (swan_bfs()) {
        cout << 0;
        return 0;
    }

    bfs();

    while (true) {
        ans++;
        while (!land[ans].empty()) {
            auto t = land[ans].front();
            arr[t.first][t.second] = '.';
            land[ans].pop();
        }
        swap(swan_q, swan_next);
        if (swan_bfs()) break;
    }

    cout << ans;

    return 0;
}