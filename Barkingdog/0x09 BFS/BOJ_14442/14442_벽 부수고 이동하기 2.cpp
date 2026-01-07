#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

int N, M, K;


int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int bfs(vector<vector<char>> &arr, vector<vector<vector<int>>> &visit) {
    queue<tuple<int, int, int>> q;
    q.emplace(0, 0, 0);
    visit[0][0][0] = 1;

    while (!q.empty()) {
        auto t = q.front();
        int crushed = get<2>(t);
//        cout << get<0>(t) << " " << get<1>(t) << ", " << crushed << "\n";
        q.pop();

        for (int i = 0; i < 4; ++i) {
            int nx = get<0>(t) + dx[i];
            int ny = get<1>(t) + dy[i];

            if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
            if (nx == N - 1 && ny == M - 1) return visit[get<0>(t)][get<1>(t)][crushed] + 1;
            if (crushed < K) {
                if (arr[nx][ny] == '1') {
                    if (visit[nx][ny][crushed + 1]) continue;
                    visit[nx][ny][crushed + 1] = visit[get<0>(t)][get<1>(t)][crushed] + 1;
                    q.emplace(nx, ny, crushed + 1);
                } else {
                    if (visit[nx][ny][crushed]) continue;
                    visit[nx][ny][crushed] = visit[get<0>(t)][get<1>(t)][crushed] + 1;
                    q.emplace(nx, ny, crushed);
                }
            } else {
                if (arr[nx][ny] == '1' || visit[nx][ny][crushed]) continue;
                visit[nx][ny][crushed] = visit[get<0>(t)][get<1>(t)][crushed] + 1;
                q.emplace(nx, ny, crushed);
            }
        }
    }

    return -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> M >> K;
    vector<vector<char>> arr(N, vector<char>(M, '0'));
    vector<vector<vector<int>>> visit(N, vector<vector<int>>(M, vector<int>(K+1,0)));

    for (int i = 0; i < N; ++i) {
        string s;
        cin >> s;
        for (int j = 0; j < M; ++j)
            arr[i][j] = s[j];
    }
    if(N == 1 && M == 1) cout << 1;
    else cout << bfs(arr, visit);

    return 0;
}