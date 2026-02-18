#include <iostream>
#include <vector>
#include <queue>

using namespace std;

long long int n, m, st, en, c;
const long long INF = 4'000'000'000'000'000'000LL;
vector<pair<long long int, int>> arr[100001];
vector<long long int> dist(100001, INF);

bool dijkstra(const long long int limit) {
    priority_queue<pair<long long int, int>, vector<pair<long long int, int>>, greater<>> q;
    fill(dist.begin(), dist.begin() + (n + 1), INF);
    dist[st] = 0;
    q.emplace(0, st);

    while (!q.empty()){
        const auto [cur_dist, cur_pos] = q.top();
        q.pop();

        if (dist[cur_pos] != cur_dist || cur_dist > c) continue;
        if (cur_pos == en) return true;
        for (const auto [nxt_dist, nxt_pos] : arr[cur_pos]){
            if (nxt_dist > limit) continue;
            long long possible_nxt_dist = cur_dist + nxt_dist;
            if (possible_nxt_dist > c) continue;
            if (possible_nxt_dist >= dist[nxt_pos]) continue;
            dist[nxt_pos] = possible_nxt_dist;
            q.emplace(possible_nxt_dist, nxt_pos);
        }
    }

    return dist[en] <= c;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int low = 0, high = 0, ans = -1;

    cin >> n >> m >> st >> en >> c;

    while (m--){
        int a, b;
        int cost;
        cin >> a >> b >> cost;
        arr[a].emplace_back(cost, b);
        arr[b].emplace_back(cost, a);
        high = max(high, cost);
    }

    while (low <= high){
        if (const int mid = (low + high) / 2; dijkstra(mid)){
            ans = mid;
            high = mid - 1;
        }
        else low = mid + 1;
    }

    cout << ans;

    return 0;
}
