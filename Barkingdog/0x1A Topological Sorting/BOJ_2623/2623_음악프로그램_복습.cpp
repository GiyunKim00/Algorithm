#include <iostream>
#include <queue>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int node_num, edge_num;
    cin >> node_num >> edge_num;

    vector<int> edge[node_num + 1], indegree(node_num + 1, 0), answer;

    while (edge_num--) {
        int count;
        cin >> count;

        vector<int> tmp(count);

        for (int i = 0; i < count; ++i) cin >> tmp[i];
        for (int i = 1; i < count; ++i) {
            edge[tmp[i - 1]].push_back(tmp[i]);
            indegree[tmp[i]]++;
        }
    }

    queue<int> q;
    for (int i = 1; i <= node_num; ++i) {
        if (!indegree[i]) {
            answer.push_back(i);
            q.push(i);
        }
    }

    while (!q.empty()) {
        const int cur_node = q.front();
        q.pop();

        for (const auto &nxt_node: edge[cur_node]) {
            if (!--indegree[nxt_node]) {
                answer.push_back(nxt_node);
                q.push(nxt_node);
            }
        }
    }
    if (answer.size() != node_num) cout << "0";
    else for (const auto &node: answer) cout << node << "\n";

    return 0;
}