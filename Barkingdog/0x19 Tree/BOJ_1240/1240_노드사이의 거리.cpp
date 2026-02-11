#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

struct edge {
    int to;
    int weight;
};

int n, m;
vector<edge> arr[1001];
int dist[1001];

void bfs(const int from, const int goal) {
    if (from == goal) {
        cout << 0 << "\n";
        return;
    }
    memset(dist, -1, sizeof(dist));
    queue<int> q;
    q.push(from);
    dist[from] = 0;

    while (!q.empty()) {
        const int t = q.front();
        q.pop();

        for (const auto [to, weight]: arr[t]) {
            if (dist[to] == -1) {
                dist[to] = dist[t] + weight;
                if (to == goal) {
                    cout << dist[to] << "\n";
                    return;
                }
                q.push(to);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    for (int i = 0; i < n - 1; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        arr[a].push_back({b, c});
        arr[b].push_back({a, c});
    }

    while (m--) {
        int a, b;
        cin >> a >> b;
        bfs(a, b);
    }

    return 0;
}