#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

queue<pair<int, int>> q;

int M, N, K;
int arr[101][101];
bool visit[101][101];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int bfs(int x, int y) {
    int cnt = 0;
    q.emplace(x, y);
    visit[x][y] = true;

    while (!q.empty()) {
        cnt++;
        auto t = q.front();
        q.pop();

        for (int i = 0; i < 4; ++i) {
            int nx = t.first + dx[i];
            int ny = t.second + dy[i];

            if (nx < 0 || ny < 0 || nx >= M || ny >= N) continue;
            if (visit[nx][ny] || arr[nx][ny] == 1) continue;

            visit[nx][ny] = true;
            q.emplace(nx, ny);
        }
    }

    return cnt;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int cnt = 0;
    vector<int> area;
    cin >> M >> N >> K;

    while (K--) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;

        for (int i = d - 1; i >= b; --i) {
            for (int j = c - 1; j >= a; --j) arr[i][j] = 1;
        }
    }

    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            if (arr[i][j] != 1 && !visit[i][j]) {
                cnt++;
                area.push_back(bfs(i, j));
            }
        }
    }

    sort(area.begin(), area.end());
    cout << cnt << "\n";
    for (auto i: area) cout << i << " ";

    return 0;
}