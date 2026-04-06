#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int node_num, edge_num, src_node, dst_node;
    cin >> node_num >> edge_num;

    vector<pair<int, int> > arr[node_num + 1];
    vector<int> dist(node_num + 1, 1e9), prev_route(node_num + 1, 0), route;
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<> > q;

    while (edge_num--) {
        int start, end, cost;
        cin >> start >> end >> cost;
        arr[start].emplace_back(cost, end);
    }

    cin >> src_node >> dst_node;

    dist[src_node] = 0;
    q.emplace(0, src_node);

    while (!q.empty()) {
        const auto [cur_cost, cur_node] = q.top();
        q.pop();

        if (dist[cur_node] != cur_cost) continue;
        for (const auto [nxt_cost, nxt_node]: arr[cur_node]) {
            if (dist[nxt_node] <= nxt_cost + dist[cur_node]) continue;
            dist[nxt_node] = nxt_cost + dist[cur_node];
            q.emplace(dist[nxt_node], nxt_node);
            prev_route[nxt_node] = cur_node;
        }
    }

    cout << dist[dst_node] << "\n";

    int node = dst_node;
    while (node) {
        route.push_back(node);
        node = prev_route[node];
    }

    cout << route.size() << "\n";
    for (auto i = route.rbegin(); i != route.rend(); ++i) cout << *i << " ";
    // reverse(route.begin(), route.end());
    // for (const auto i: route) cout << i << " ";

    return 0;
}
