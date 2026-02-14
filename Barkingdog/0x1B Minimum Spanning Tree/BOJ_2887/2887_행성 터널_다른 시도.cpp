#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> p;
tuple<int, int, int, int> tmp[100000];
tuple<int, int, int> edge_x[100000], edge_y[100000], edge_z[100000], edge[300000];
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

bool compare_y(const tuple<int, int, int, int> &a, const tuple<int, int, int, int> &b) {
    return get<1>(a) < get<1>(b);
}

bool compare_z(const tuple<int, int, int, int> &a, const tuple<int, int, int, int> &b) {
    return get<2>(a) < get<2>(b);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, edge_cnt = 0, cnt = 0;
    long long ans = 0;
    cin >> n;
    p.assign(n, -1);

    for (int i = 0; i < n; ++i) {
        int x, y, z;
        cin >> x >> y >> z;
        tmp[i] = {x, y, z, i};
    }
    sort(tmp, tmp + n);

    for (int i = 0; i < n - 1; ++i) {
        const auto [x1, y1, z1, id1] = tmp[i];
        const auto [x2, y2, z2, id2] = tmp[i + 1];
        edge_x[edge_cnt++] = {abs(x1 - x2), id1, id2};
    }
    for (int i = 0; i < edge_cnt; ++i) edge[i] = edge_x[i];

    sort(tmp, tmp + n, compare_y);
    edge_cnt = 0;
    for (int i = 0; i < n - 1; ++i) {
        const auto [x1, y1, z1, id1] = tmp[i];
        const auto [x2, y2, z2, id2] = tmp[i + 1];
        edge_y[edge_cnt++] = {abs(y1 - y2), id1, id2};
    }
    for (int i = edge_cnt; i < 2 * edge_cnt; ++i) edge[i] = edge_y[i - edge_cnt];

    sort(tmp, tmp + n, compare_z);
    edge_cnt = 0;
    for (int i = 0; i < n - 1; ++i) {
        const auto [x1, y1, z1, id1] = tmp[i];
        const auto [x2, y2, z2, id2] = tmp[i + 1];
        edge_z[edge_cnt++] = {abs(z1 - z2), id1, id2};
    }
    for (int i = 2 * edge_cnt; i < 3 * edge_cnt; ++i) edge[i] = edge_z[i - 2*edge_cnt];

    sort(edge, edge + 3 * edge_cnt);

    for (int i = 0; i < 3 * edge_cnt && cnt < n - 1; ++i) {
        auto [cost, a, b] = edge[i];
        if (!uni(a, b)) continue;
        ans += cost;
        cnt++;
    }

    cout << ans;

    return 0;
}