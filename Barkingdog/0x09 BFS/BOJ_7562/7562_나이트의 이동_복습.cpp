#include <iostream>
#include <queue>

using namespace std;

int I;

int dx[8] = {1, 2, 2, 1, -1, -2, -2, -1};
int dy[8] = {2, 1, -1, -2, -2, -1, 1, 2};

int bfs(const int x, const int y, const int dst_x, const int dst_y, vector<vector<int> > &visit) {
    queue<pair<int, int> > q;
    q.emplace(x, y);
    visit[x][y] = 1;

    while (!q.empty()) {
        const auto t = q.front();
        q.pop();

        if (t.first == dst_x && t.second == dst_y) return visit[t.first][t.second] - 1;

        for (int i = 0; i < 8; ++i) {
            int nx = t.first + dx[i];
            int ny = t.second + dy[i];

            if (nx < 0 || ny < 0 || nx >= I || ny >= I) continue;
            if (visit[nx][ny]) continue;

            q.emplace(nx, ny);
            visit[nx][ny] = visit[t.first][t.second] + 1;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;

    while (N--) {
        cin >> I;

        vector<vector<int> > visit(I, vector<int>(I, 0));

        int src_x, src_y, dst_x, dst_y;
        cin >> src_x >> src_y >> dst_x >> dst_y;

        cout << bfs(src_x, src_y, dst_x, dst_y, visit) << "\n";
    }

    return 0;
}
