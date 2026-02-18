#include <iostream>
#include <vector>
#include <queue>

using namespace std;
int n, x;

void dijkstra(vector<pair<int, int>> *arr, vector<int> &dist) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> q;
    q.emplace(0, x);

    while (!q.empty()){
        const auto [cur_dist, cur_pos] = q.top();
        q.pop();
        if (dist[cur_pos] != cur_dist) continue;
        for (const auto [nxt_dist, nxt_pos] : arr[cur_pos]){
            if (dist[nxt_pos] <= dist[cur_pos] + nxt_dist) continue;
            dist[nxt_pos] = dist[cur_pos] + nxt_dist;
            q.emplace(dist[nxt_pos], nxt_pos);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int m, ans = 0;
    cin >> n >> m >> x;
    vector<pair<int, int>> arr[1001], rev_arr[1001];
    vector<int> dist(1001, 1e9), rev_dist(1001, 1e9);

    while (m--){
        int a, b, cost;
        cin >> a >> b >> cost;
        arr[a].emplace_back(cost, b);
        rev_arr[b].emplace_back(cost, a);
    }
    dist[x] = rev_dist[x] = 0;

    dijkstra(arr, dist);
    dijkstra(rev_arr, rev_dist);

    for (int i = 1; i <= n; ++i){
        if (i == x) continue;
        ans = max(ans, dist[i] + rev_dist[i]);
    }

    cout << ans;
    return 0;
}