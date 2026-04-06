#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int node_num, edge_num, node_cnt = 1, answer = 0;
    cin >> node_num >> edge_num;
    vector<pair<int, int>> edge[node_num + 1];
    vector<bool> visit(node_num + 1, false);
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<> > q;

    while (edge_num--) {
        int start, end, cost;
        cin >> start >> end >> cost;
        edge[start].emplace_back(cost, end);
        edge[end].emplace_back(cost, start);
    }

    visit[1] = true;
    for (const auto &i : edge[1]) q.emplace(i.first, i.second);

    while (node_cnt < node_num) {
        const auto [cost, end] = q.top();
        q.pop();

        if (visit[end]) continue;
        visit[end] = true;

        node_cnt++;
        answer += cost;
        for (const auto &i : edge[end])
            if (!visit[i.second]) q.emplace(i.first, i.second);
    }

    cout << answer;

    return 0;
}