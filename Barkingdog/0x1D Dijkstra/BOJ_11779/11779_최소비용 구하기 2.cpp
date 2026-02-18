#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, src, dst;
    cin >> n >> m;

    vector<pair<int, int>> arr[1001];
    vector<int> dist(1001, 1e9), path(1001, 1e9), ans;
    while (m--){
        int a, b, cost;
        cin >> a >> b >> cost;
        arr[a].emplace_back(cost, b);
    }

    cin >> src >> dst;
    dist[src] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> q;
    q.emplace(0, src);

    while (!q.empty()){
        const auto [cur_dist, cur_pos] = q.top();
        q.pop();
        if (dist[cur_pos] != cur_dist) continue;
        for (const auto [nxt_dist, nxt_pos] : arr[cur_pos]){
            if (dist[nxt_pos] <= dist[cur_pos] + nxt_dist) continue;
            dist[nxt_pos] = dist[cur_pos] + nxt_dist;
            q.emplace(dist[nxt_pos], nxt_pos);
            path[nxt_pos] = cur_pos;
        }
    }
    int idx = dst;
    while (idx != src){
        ans.push_back(idx);
        idx = path[idx];
    }

    ans.push_back(src);

    reverse(ans.begin(), ans.end());

    cout << dist[dst] << "\n" << ans.size() << "\n";
    for (const auto i : ans) cout << i << " ";

    return 0;
}