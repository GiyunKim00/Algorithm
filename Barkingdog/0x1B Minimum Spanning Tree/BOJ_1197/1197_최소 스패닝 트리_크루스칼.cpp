#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> p(10001, -1);
tuple<int, int, int> edge[100000];

int find(const int x) {
    if (p[x] < 0) return x;
    return p[x] = find(p[x]);
}

bool uni(int u, int v) {
    u = find(u);
    v = find(v);

    if (u == v) return false;
    if (p[v] < p[u]) swap(u, v);
    if (p[v] == p[u]) p[u]--;
    p[v] = u;

    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int v, e, cnt = 0, ans = 0;
    cin >> v >> e;

    for (int i = 0; i < e; ++i) {
        int a, b, cost;
        cin >> a >> b >> cost;
        edge[i] = {cost, a, b};
    }

    sort(edge, edge + e);

    for (int i = 0; i < e && cnt < v - 1; ++i) {
        int a, b, cost;
        tie(cost, a, b) = edge[i];
        if (!uni(a, b)) continue;
        cnt++;
        ans += cost;
    }

    cout << ans;

    return 0;
}