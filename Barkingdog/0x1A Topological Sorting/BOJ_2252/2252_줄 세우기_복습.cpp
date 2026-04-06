#include <iostream>
#include <queue>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int node_num, edge_num;

    cin >> node_num >> edge_num;

    vector<int> arr[node_num + 1], indegree(node_num + 1, 0), answer;

    while (edge_num--) {
        int start, end;
        cin >> start >> end;
        arr[start].push_back(end);
        indegree[end]++;
    }

    queue<int> q;
    for (int i = 1; i <= node_num; ++i)
        if (!indegree[i]) {
            q.push(i);
            answer.push_back(i);
        }

    while (!q.empty()) {
        const int cur_node = q.front();
        q.pop();

        for (const auto &nxt_node: arr[cur_node]) {
            if (!--indegree[nxt_node]) {
                q.push(nxt_node);
                answer.push_back(nxt_node);
            }
        }
    }

    for (const auto &i : answer) cout << i << " ";

    return 0;
}