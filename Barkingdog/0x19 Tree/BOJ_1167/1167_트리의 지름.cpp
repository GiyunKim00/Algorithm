#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

struct edge {
    int child;
    int value;
};

vector<edge> arr[100001];
bool visit[100001];
int max_length_node = 0, max_length = 0, dist[100001];

void bfs(const int idx) {
    queue<int> q;
    visit[idx] = true;
    q.push(idx);

    while (!q.empty()) {
        const int k = q.front();
        q.pop();

        for (const auto &[child, value]: arr[k]) {
            if (visit[child]) continue;
            visit[child] = true;
            dist[child] = dist[k] + value;
            if (dist[child] > max_length) {
                max_length = dist[child];
                max_length_node = child;
            }
            q.push(child);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;

    cin >> n;

    while (n--) {
        int a, b = 0, c;
        cin >> a;
        while (true) {
            cin >> b;
            if (b == -1) break;
            cin >> c;
            arr[a].push_back({b, c});
        }
    }

    bfs(1);
    memset(dist, 0, sizeof(dist));
    memset(visit, 0, sizeof(visit));
    max_length = 0;
    bfs(max_length_node);
    cout << dist[max_length_node];

    return 0;
}