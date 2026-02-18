#include <iostream>
#include <queue>
#include <vector>
#include <tuple>

using namespace std;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> m >> n;
    int arr[n + 1][m + 1];
    vector<vector<int>> dist(n + 1, vector<int>(m + 1, 1e9));

    dist[1][1] = 0;

    for (int i = 1; i <= n; ++i){
        string s;
        cin >> s;
        for (int j = 1; j <= m; ++j)arr[i][j] = (s[j - 1] - '0');
    }

    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> q;
    q.emplace(0, 1, 1);

    while (!q.empty()){
        const auto [cur_dist, cur_x, cur_y] = q.top();
        q.pop();
        if (dist[cur_x][cur_y] != cur_dist) continue;
        for (int i = 0; i < 4; ++i){
            const int nxt_x = cur_x + dx[i];
            const int nxt_y = cur_y + dy[i];
            if (nxt_x < 1 || nxt_y < 1 || nxt_x > n || nxt_y > m) continue;
            const int nxt_dist = arr[nxt_x][nxt_y];
            if (dist[nxt_x][nxt_y] <= dist[cur_x][cur_y] + nxt_dist) continue;
            dist[nxt_x][nxt_y] = dist[cur_x][cur_y] + nxt_dist;
            q.emplace(dist[nxt_x][nxt_y], nxt_x, nxt_y);
        }
    }

    cout << dist[n][m];

    return 0;
}