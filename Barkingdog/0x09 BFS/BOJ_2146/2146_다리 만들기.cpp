#include <iostream>
#include <queue>

using namespace std;

int N;
int arr[100][100];
int visit[100][100];

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int bfs(int x, int y, int land, int mode) {
    queue<pair<int, int>> q;
    q.emplace(x, y);
    visit[x][y] = 1;

    while (!q.empty()) {
        auto t = q.front();
        q.pop();
        for (int i = 0; i < 4; ++i) {
            int nx = t.first + dx[i];
            int ny = t.second + dy[i];

            if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
            if (!mode) {
                if (arr[nx][ny] == 0 || visit[nx][ny] == 1) continue;
                visit[nx][ny] = 1;
                arr[nx][ny] = land;
                q.emplace(nx, ny);
            } else {
                if (arr[nx][ny] == land || visit[nx][ny] != 0) continue;
                if (arr[nx][ny] != 0) return visit[t.first][t.second] - 1;
                visit[nx][ny] = visit[t.first][t.second] + 1;
                q.emplace(nx, ny);
            }
        }
    }

    return 0;
}

bool isBorder(int x, int y) {
    for (int d = 0; d < 4; ++d) {
        int nx = x + dx[d];
        int ny = y + dy[d];
        if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
        if (arr[nx][ny] == 0) return true;
    }
    return false;
}

int main() {
    int cnt = 1;
    int shortest_way = 1000;
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> arr[i][j];
        }
    }

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (visit[i][j] == 0 && arr[i][j] == 1) {
                cnt++;
                arr[i][j] = cnt;
                bfs(i, j, cnt, 0);
            }
        }
    }


    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (arr[i][j] != 0 && isBorder(i, j)) {
                fill(&visit[0][0], &visit[N - 1][N - 1] + 1, 0);
                int min_way = bfs(i, j, arr[i][j], 1);
                if (min_way) shortest_way = min(shortest_way, min_way);
            }
        }
    }

    cout << shortest_way;

    return 0;
}