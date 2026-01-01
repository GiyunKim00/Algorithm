#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

int L, R, C;
char arr[31][31][31];
int visit[31][31][31];

int dx[8] = {0, 1, 0, -1, 0, 0};
int dy[8] = {1, 0, -1, 0, 0, 0};
int dz[8] = {0, 0, 0, 0, 1, -1};

int bfs(int x, int y, int z) {
    queue<tuple<int, int, int>> q;
    q.emplace(x, y, z);
    visit[x][y][z] = 1;

    while (!q.empty()) {
        auto t = q.front();
        q.pop();

        for (int i = 0; i < 8; ++i) {
            int nx = get<0>(t) + dx[i];
            int ny = get<1>(t) + dy[i];
            int nz = get<2>(t) + dz[i];
            int now = visit[get<0>(t)][get<1>(t)][get<2>(t)];

            if (nx < 0 || ny < 0 || nz < 0 || nx >= R || ny >= C || nz >= L) continue;
            if (arr[nx][ny][nz] == 'E') return now;
            if (visit[nx][ny][nz] || arr[nx][ny][nz] == '#') continue;

            q.emplace(nx, ny, nz);
            visit[nx][ny][nz] = now + 1;
        }
    }

    return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    while(true) {
        tuple<int, int, int> start;
        cin >> L >> R >> C;
        if(!L && !R && !C) break;
        fill(&visit[0][0][0],&visit[30][30][30],0);
        for (int i = 0; i < L; ++i) {
            for (int j = 0; j < R; ++j) {
                string s;
                cin >> s;
                for (int k = 0; k < C; ++k) {
                    arr[j][k][i] = s[k];
                    if (s[k] == 'S') start = {j, k, i};
                }
            }
        }

        int ans = bfs(get<0>(start), get<1>(start), get<2>(start));
        if (ans) cout << "Escaped in " << ans << " minute(s).\n";
        else cout << "Trapped!\n";
    }

    return 0;
}