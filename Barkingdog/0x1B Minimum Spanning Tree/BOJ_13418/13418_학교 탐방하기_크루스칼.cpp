#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>

using namespace std;

int n, m;

tuple<int, int, int> edge[500501];
vector<int> p(1001, -1);

bool compare(const tuple<int, int, int>& a, const tuple<int, int, int>& b) {
    return get<0>(a) > get<0>(b);
}

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

    int max_val = 0, min_val = 0, cnt = 0;

    cin >> n >> m;
    for (int i = 0; i <= m; ++i){
        int a, b, cost;
        cin >> a >> b >> cost;
        edge[i] = {cost, a, b};
    }

    sort(edge, edge + m + 1);

    for (int i = 0; i <= m && cnt < n; ++i){
        auto [cost, a, b] = edge[i];
        if (!uni(a, b)) continue;
        cnt++;
        if (!cost) max_val++;
    }

    cnt = 0;
    fill(p.begin(), p.end(), -1);
    sort(edge, edge + m + 1, compare);
    for (int i = 0; i <= m && cnt < n; ++i){
        auto [cost, a, b] = edge[i];
        if (!uni(a, b)) continue;
        cnt++;
        if (!cost) min_val++;
    }

    cout << max_val * max_val - min_val * min_val;

    return 0;
}