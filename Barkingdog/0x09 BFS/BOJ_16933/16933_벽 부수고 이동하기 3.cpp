#include <iostream>
#include <queue>

using namespace std;

int N, M, K;
char arr[1000][1000];
bool visit[1000][1000][11][2];

struct State {
    short x, y;
    int crushed;
    int night;
    int dist;

    State(short _x, short _y, int _c, bool _n, int _d)
            : x(_x), y(_y), crushed(_c), night(_n), dist(_d) {}
};

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int bfs() {
    queue<State> q;
    q.emplace(0, 0, 0, 0, 1);
    visit[0][0][0][0] = true;

    while (!q.empty()) {
        auto t = q.front();
        bool shouldWait = false;
        int crushed = t.crushed;
        int isNight = t.night % 2;
        int dist = t.dist;
//        cout << get<0>(t) << " " << get<1>(t) << ", crushed : " << crushed << ", isNight : " << isNight
//             << ", isVisited : " << visit[get<0>(t)][get<1>(t)][crushed][isNight] << "\n";
        q.pop();

        for (int i = 0; i < 4; ++i) {
            int nx = t.x + dx[i];
            int ny = t.y + dy[i];
            if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
            if (nx == N - 1 && ny == M - 1) return dist + 1;
            if (crushed < K) {
                if (arr[nx][ny] == '1') {
                    if (visit[nx][ny][crushed + 1][!isNight]) continue;
                    if(isNight) {
                        shouldWait = true;
                    } else {
                        visit[nx][ny][crushed + 1][!isNight] = true;
                        q.emplace(nx, ny, crushed + 1, !isNight, dist + 1);
                    }
                } else {
                    if (visit[nx][ny][crushed][!isNight]) continue;
                    visit[nx][ny][crushed][!isNight] = true;
                    q.emplace(nx, ny, crushed, !isNight, dist + 1);
                }
            } else {
                if (arr[nx][ny] == '1' || visit[nx][ny][crushed][!isNight]) continue;
                visit[nx][ny][crushed][!isNight] = true;
                q.emplace(nx, ny, crushed, !isNight, dist + 1);
            }
        }

        if (shouldWait && !visit[t.x][t.y][crushed][!isNight]) {
            visit[t.x][t.y][crushed][!isNight] = true;
            q.emplace(t.x, t.y, crushed, !isNight, dist + 1);
        }
    }

    return -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> M >> K;

    for (int i = 0; i < N; ++i) {
        string s;
        cin >> s;
        for (int j = 0; j < M; ++j)
            arr[i][j] = s[j];
    }
    if (N == 1 && M == 1) cout << 1;
    else cout << bfs();
}