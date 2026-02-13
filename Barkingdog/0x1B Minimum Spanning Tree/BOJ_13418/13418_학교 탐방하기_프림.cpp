#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m;
vector<pair<int, int>> arr[1001];

int prim(const bool mode) {
    vector<bool> visit(1001, false);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> q;
    int cnt = 0, ans = 0;
    visit[0] = true;
    for (auto [b, cost] : arr[0]){
        if (mode) cost = cost == 0 ? 1 : 0;
        q.emplace(cost, b);
    }

    while (cnt < n){
        auto[cost, b] = q.top();
        q.pop();
        if (visit[b]) continue;
        visit[b] = true;
        cnt++;
        if (mode && cost) ans++;
        if (!mode && !cost) ans++;
        for (auto [nxt, nxt_cost] : arr[b]){
            if (visit[nxt]) continue;
            if (mode) nxt_cost = nxt_cost == 0 ? 1 : 0;
            q.emplace(nxt_cost, nxt);
        }
    }
    return ans * ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    for (int i = 0; i <= m; ++i){
        int a, b, cost;
        cin >> a >> b >> cost;
        arr[a].emplace_back(b, cost);
        arr[b].emplace_back(a, cost);
    }

    cout << prim(false) - prim(true);

    return 0;
}