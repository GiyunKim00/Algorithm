#include <iostream>
#include <queue>
#include <vector>

using namespace std;

void dijkstra(int st, vector<pair<long long int, int>>* arr, vector<long long int>& dist) {
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> q;
    q.emplace(0, st);
    dist[st] = 0;

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

    int n, m, v1, v2;

    cin >> n >> m;

    vector<pair<long long, int>> arr[n + 1];
    vector<long long int> s_dist(n + 1, 1e9), v_dist(n + 1, 1e9), e_dist(n + 1, 1e9);

    while (m--){
        int a, b, cost;
        cin >> a >> b >> cost;
        arr[a].emplace_back(cost, b);
        arr[b].emplace_back(cost, a);
    }

    cin >> v1 >> v2;

    dijkstra(1, arr, s_dist);
    dijkstra(v1, arr, v_dist);
    dijkstra(n, arr, e_dist);

    long long int path1 = s_dist[v1] + v_dist[v2] + e_dist[v2], path2 = s_dist[v2] + v_dist[v2] + e_dist[v1];
    if (path1 >= 1e9 && path2 >= 1e9) cout << "-1";
    else cout << min(path1, path2);

    return 0;
}