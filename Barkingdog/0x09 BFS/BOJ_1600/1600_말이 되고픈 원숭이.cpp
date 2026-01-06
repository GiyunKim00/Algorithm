#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

int K, W, H;

vector<vector<int>> arr(201, vector<int>(201, 0));
vector<vector<vector<int>>> visit(201, vector<vector<int>>(201, vector<int>(31, 0)));


int dx[12] = {0, 1, 0, -1, 1, 2, 2, 1, -1, -2, -2, -1};
int dy[12] = {1, 0, -1, 0, 2, 1, -1, -2, -2, -1, 1, 2};

int bfs() {
    queue<tuple<int, int, int>> q;
    q.emplace(0, 0, 0);
    visit[0][0][0] = 1;

    while (!q.empty()) {
        auto t = q.front();
        q.pop();
        int isHorse, horse = 12;
        isHorse = get<2>(t);
        if (isHorse >= K) horse = 4;

        for (int i = 0; i < horse; ++i) {
            int nx = get<0>(t) + dx[i];
            int ny = get<1>(t) + dy[i];

            if (nx < 0 || ny < 0 || nx >= H || ny >= W) continue;

            if (nx == H - 1 && ny == W - 1) return visit[get<0>(t)][get<1>(t)][isHorse];
            if (!arr[nx][ny]) {
                if (i > 3) {
                    if (isHorse >= K) continue;
                    if (visit[nx][ny][isHorse + 1]) continue;
                    visit[nx][ny][isHorse + 1] = visit[get<0>(t)][get<1>(t)][isHorse] + 1;
                    q.emplace(nx, ny, isHorse + 1);
                } else {
                    if (visit[nx][ny][isHorse]) continue;
                    visit[nx][ny][isHorse] = visit[get<0>(t)][get<1>(t)][isHorse] + 1;
                    q.emplace(nx, ny, isHorse);
                }
            }
        }
    }

    return -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> K >> W >> H;
    if (W == 1 && H == 1) cout << 0;
    else {
        for (int i = 0; i < H; ++i) {
            for (int j = 0; j < W; ++j)
                cin >> arr[i][j];
        }

        cout << bfs();
    }
    return 0;
}