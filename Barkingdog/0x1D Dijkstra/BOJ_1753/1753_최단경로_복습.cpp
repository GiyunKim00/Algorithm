#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int node_num, edge_num, start_node;
    cin >> node_num >> edge_num >> start_node;

    vector<pair<int, int> > arr[node_num + 1];
    vector<int> dist(node_num + 1, 1e9), pre(node_num + 1, 0);
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<> > q;

    while (edge_num--) {
        int start, end, cost;
        cin >> start >> end >> cost;
        arr[start].emplace_back(cost, end);
    }

    dist[start_node] = 0;
    q.emplace(0, start_node);

    while (!q.empty()) {
        const auto [cur_cost, cur_node] = q.top();
        q.pop();
        if (dist[cur_node] != cur_cost) continue;

        for (const auto [nxt_cost, nxt_node]: arr[cur_node]) {
            if (dist[nxt_node] <= dist[cur_node] + nxt_cost) continue;
            dist[nxt_node] = dist[cur_node] + nxt_cost;
            q.emplace(dist[nxt_node], nxt_node);
            pre[nxt_node] = cur_node;
        }
    }

    for (int i = 1; i <= node_num; ++i) {
        if (dist[i] == 1e9) cout << "INF\n";
        else {
            cout << "dist: " << dist[i] <<" / [" << pre[i] << " -> " << i << "]\n";
        }
    }
}