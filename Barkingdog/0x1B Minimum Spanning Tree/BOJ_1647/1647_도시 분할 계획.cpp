#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> p(100001, -1);
tuple<int, int, int> edge[1000000];

int find(const int x) {
    if (p[x] < 0) return x;
    return p[x] = find(p[x]);
}

bool uni(int u, int v) {
    u = find(u);
    v = find(v);

    if (u == v) return false;
    if (p[v] < p[u]) swap(v, u);
    if (p[v] == p[u]) p[u]--;
    p[v] = u;
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, cnt = 0, ans = 0, max_val = 0;

    cin >> n >> m;
    for (int i = 0; i < m; ++i){
        int a, b, cost;
        cin >> a >> b >> cost;
        edge[i] = {cost, a, b};
    }
    sort(edge, edge + m);

    for (int i = 0; i < m && cnt < n - 1; ++i){
        int cost, a, b;
        tie(cost, a, b) = edge[i];
        if (!uni(a, b)) continue;
        ans += cost;
        cnt++;
        max_val = max(max_val, cost);
    }

    cout << ans - max_val;

    return 0;
}