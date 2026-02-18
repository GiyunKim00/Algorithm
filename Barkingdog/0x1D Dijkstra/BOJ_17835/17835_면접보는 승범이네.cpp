#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, k, ans_node;
    long long int ans_dist = 0;
    cin >> n >> m >> k;

    vector<pair<long long int, int>> arr[n + 1];
    vector<long long int> dist(n + 1, 4e18);
    vector<bool> check(n + 1, false);

    /**
     * 역방향 그래프 다익스트라.
     * 모든 정점 -> 특정 정점(또는 여러 정점 집합)을 구할 땐 역방향 그래프.
     *
     * 기본적으로 다익스트라는 '한 시작점 -> 모든 정점 간 최단거리'를 구하는 알고리즘임.
     * 그런데, 모든 정점 -> 특정 정점(또는 여러 정점 집합)의 최단거리를 구해야하는 경우, 간선을 역방향으로 뒤집고, 특정 정점을 시작위치(dist=0)으로 설정해서 해결할 수 있음.
     */
    while (m--){
        int a, b, cost;
        cin >> a >> b >> cost;
        arr[b].emplace_back(cost, a);
    }

    priority_queue<pair<long long int, int>, vector<pair<long long int, int>>, greater<>> q;

    while (k--){
        int a;
        cin >> a;
        check[a] = true;
        dist[a] = 0;
        q.emplace(0, a);
    }

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

    for (int i = 1; i <= n; ++i){
        if (check[i] || dist[i] == 4e18) continue;
        if (ans_dist < dist[i]){
            ans_dist = dist[i];
            ans_node = i;
        }
    }

    cout << ans_node << "\n" << ans_dist;

    return 0;
}