#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int n;
vector<int> arr[51];
int visit[51][51];

void bfs(const int x) {
    queue<int> q;
    q.push(x);
    visit[x][x] = 0;

    while (!q.empty()) {
        const int k = q.front();
        q.pop();

        for (const auto idx: arr[k]) {
            if (visit[x][idx] == -1) {
                visit[x][idx] = visit[x][k] + 1;
                q.push(idx);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    vector<int> dist(n + 1), ans;
    int a = 0, b = 0, min_total_score = 100;

    while (true) {
        cin >> a >> b;
        if (a == -1) break;
        arr[a].push_back(b);
        arr[b].push_back(a);
    }

    memset(visit, -1, sizeof(visit));

    for (int i = 1; i <= n; ++i) bfs(i);

    for (int i = 1; i <= n; ++i) {
        int max_dist = 0;
        for (int j = 1; j <= n; ++j) if (i != j) max_dist = max(max_dist, visit[i][j]);
        dist[i] = max_dist;
        if (max_dist < min_total_score) min_total_score = max_dist;
    }

    for (int i = 1; i <= n; ++i) if (dist[i] == min_total_score) ans.push_back(i);

    cout << min_total_score << " " << ans.size() << "\n";
    for (const auto i: ans) cout << i << " ";

    return 0;
}