#include <iostream>
#include <queue>

using namespace std;

int I;

int dx[8] = {1, 2, 2, 1, -1, -2, -2, -1};
int dy[8] = {2, 1, -1, -2, -2, -1, 1, 2};

int bfs(int x, int y, vector<vector<int>> &board, vector<vector<int>> &visit) {
    queue<pair<int, int>> q;
    q.emplace(x, y);
    visit[x][y] = 0;

    while (!q.empty()) {
        auto t = q.front();
        q.pop();

        for (int i = 0; i < 8; ++i) {
            int nx = t.first + dx[i];
            int ny = t.second + dy[i];

            if (nx < 0 || ny < 0 || nx >= I || ny >= I) continue;
            if (visit[nx][ny]) continue;
            if (board[nx][ny] == 1) return visit[t.first][t.second] + 1;

            visit[nx][ny] = visit[t.first][t.second] + 1;
            q.emplace(nx, ny);
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

        vector<vector<int>> board(I, vector<int>(I, 0));
        vector<vector<int>> visit(I, vector<int>(I, 0));

        int knight_x, knight_y;
        cin >> knight_x >> knight_y;

        int togo_x, togo_y;
        cin >> togo_x >> togo_y;
        board[togo_x][togo_y] = 1;

        if(knight_x == togo_x && knight_y == togo_y) {
            cout << 0 << "\n";
            continue;
        }

        cout << bfs(knight_x, knight_y, board, visit) << "\n";
    }

    return 0;
}