#include <iostream>
#include <queue>

using namespace std;

int N, M;

int arr[101][101];
bool visit[101][101];

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

queue<pair<int, int>> q_arr[101][101];

int bfs() {
    queue<pair<int, int>> q;
    int cnt = 1;
    arr[1][1] = 1;
    visit[1][1] = true;
    q.emplace(1, 1);

    while (!q.empty()) {
        auto t = q.front();
//        cout << t.first << " " << t.second << "\n";
        q.pop();
        while (!q_arr[t.first][t.second].empty()) {
            auto light = q_arr[t.first][t.second].front();
            if (arr[light.first][light.second] == 0) {
//                cout << "turn on : " << light.first << " " << light.second << "\n";
                arr[light.first][light.second] = 1;
                cnt++;
                for (int i = 0; i < 4; ++i) {
                    int nx = light.first + dx[i];
                    int ny = light.second + dy[i];
                    if (nx < 1 || ny < 1 || nx > N || ny > N) continue;
                    if (arr[nx][ny] == 1 && visit[nx][ny]) {
                        q.emplace(light.first, light.second);
                        visit[light.first][light.second] = true;
                        break;
                    }
                }
            }
            q_arr[t.first][t.second].pop();
        }

//        for (int i = 1; i <= N; ++i) {
//            for (int j = 1; j <= N; ++j)
//                cout << arr[i][j] << " ";
//            cout << "\n";
//        }
//        cout << "\n";

        for (int i = 0; i < 4; ++i) {
            int nx = t.first + dx[i];
            int ny = t.second + dy[i];

            if (nx < 1 || ny < 1 || nx > N || ny > N) continue;
            if (arr[nx][ny] == 0 || visit[nx][ny]) continue;

            visit[nx][ny] = true;
            q.emplace(nx, ny);
        }
    }
    return cnt;
}

int main() {
//    ios::sync_with_stdio(false);
//    cin.tie(nullptr);
//    cout.tie(nullptr);
    cin >> N >> M;
    int a, b, c, d;

    for (int i = 0; i < M; ++i) {
        cin >> a >> b >> c >> d;
        q_arr[a][b].emplace(c, d);
    }

    cout << bfs();

    return 0;
}