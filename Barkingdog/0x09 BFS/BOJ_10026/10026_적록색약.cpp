#include <iostream>
#include <queue>

using namespace std;

int N;
char arr[101][101];
queue<pair<int, int>> q;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void bfs(int x, int y, vector<vector<bool>> &visit, char color, bool amblyopia) {
    q.emplace(x, y);
    visit[x][y] = true;
//    if(amblyopia) cout << "amblyopia\n";
//    else cout <<"general\n";

    while (!q.empty()) {
        auto t = q.front();
        q.pop();
//        cout << t.first << " " << t.second << "\n";
        for (int i = 0; i < 4; ++i) {
            int nx = t.first + dx[i];
            int ny = t.second + dy[i];

            if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
            if (visit[nx][ny]) continue;
            if (amblyopia) {
                if (color == 'B') {
                    if (arr[nx][ny] == 'R' || arr[nx][ny] == 'G') continue;
                } else {
                    if (arr[nx][ny] == 'B') continue;
                }
            } else {
                if (arr[nx][ny] != color) continue;
            }

            q.emplace(nx, ny);
            visit[nx][ny] = true;
        }
    }

}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;

    for (int i = 0; i < N; ++i) {
        string s;
        cin >> s;
        for (int j = 0; j < N; ++j) arr[i][j] = s[j];
    }
    for (int k = 0; k < 2; ++k) {
        vector<vector<bool>> visit(101, vector<bool>(101, false));
        int cnt = 0;
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                if (!visit[i][j]) {
                    cnt++;
                    bfs(i, j, visit, arr[i][j], k);
                }
            }
        }
        cout << cnt << " ";
    }

    return 0;
}