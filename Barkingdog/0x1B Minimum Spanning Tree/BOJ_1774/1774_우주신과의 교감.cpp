#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;
tuple<double, int, int> edge[500001];
pair<int, int> tmp[1001];
vector<int> p(1001, -1);

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

double distance(const int x1, const int y1, const int x2, const int y2) {
    return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, edge_cnt = 0, cnt = 0;
    double ans = 0;
    cin >> n >> m;

    for (int i = 1; i <= n; ++i) {
        int x, y;
        cin >> x >> y;
        tmp[i] = {x, y};
    }
    for (int i = 1; i < n; ++i) {
        for (int j = i + 1; j <= n; ++j) {
            auto [x1, y1] = tmp[i];
            auto [x2, y2] = tmp[j];
            edge[edge_cnt++] = {distance(x1, y1, x2, y2), i, j};
        }
    }

    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        uni(a, b);
    }

    sort(edge, edge + edge_cnt);

    for (int i = 0; i < edge_cnt && cnt < n - 1; ++i) {
        auto [cost, a, b] = edge[i];
        if (!uni(a, b)) continue;
        cnt++;
        ans += cost;
    }
    cout << fixed;
    cout.precision(2);
    cout << ans;

    return 0;
}