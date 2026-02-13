#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

tuple<int, int, int> edge[200001];
vector<int> p(100001, -1);
int n, well[100001];

int find(const int x) {
    if (p[x] < 0) return x;
    return p[x] = find(p[x]);
}

bool uni(int u, int v) {
    u = find(u);
    v = find(v);

    if (u == v) return false;
    if (p[v] < p[u]) swap(u, v);
    if (p[u] == p[v]) p[u]--;
    p[v] = u;
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int cnt = 0, edge_cnt = 0, ans = 0;

    cin >> n;

    for (int i = 1; i <= n; ++i) cin >> well[i];

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            int cost;
            cin >> cost;
            if (i < j) edge[edge_cnt++] = {cost, i, j};
        }
    }

    for (int i = 1; i <= n; ++i) {
        edge[edge_cnt++] = {well[i], 0, i};
    }

    sort(edge, edge + edge_cnt);


    for (int i = 0; i < edge_cnt && cnt < n; ++i) {
        int cost, a, b;
        tie(cost, a, b) = edge[i];
        if (!uni(a, b)) continue;
        cnt++;
        ans += cost;
    }

    cout << ans;

    return 0;
}