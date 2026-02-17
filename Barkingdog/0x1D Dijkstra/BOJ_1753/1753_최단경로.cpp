#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, s;
    cin >> n >> m >> s;

    vector<pair<int, int>> arr[20001];
    vector<int> dist(20001, 1e9);

    while (m--){
        int a, b, cost;
        cin >> a >> b >> cost;
        arr[a].emplace_back(cost, b);
    }

    dist[1] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> q;
    q.emplace(0, 1);

    while (!q.empty()){
        const auto [cur_dist, cur_pos] = q.top();
        q.pop();
        if (dist[cur_pos] != cur_dist) continue;
        for (const auto [nxt_dist, nxt_pos] : arr[cur_pos]){
            if (dist[nxt_pos] < dist[cur_pos] + nxt_dist) continue;
            dist[nxt_pos] = dist[cur_pos] + nxt_dist;
            q.emplace(dist[nxt_pos], nxt_pos);
        }
    }

    for (int i = 1; i <= n; ++i){
        if (dist[i] == 1e9) cout << "INF\n";
        else cout << dist[i] << "\n";
    }

    return 0;
}