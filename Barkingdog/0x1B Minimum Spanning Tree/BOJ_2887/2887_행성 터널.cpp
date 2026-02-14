#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

tuple<int, int, int, int> tmp[100000];
tuple<int, int, int> edge_x[100000], edge_y[100000], edge_z[100000];
vector<int> p(100001, -1);

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

    int n, edge_cnt = 0, cnt = 0, idx_x = 0, idx_y = 0, idx_z = 0;
    long long ans = 0;
    cin >> n;

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
    sort(edge_x, edge_x + edge_cnt);

    sort(tmp, tmp + n, compare_y);
    edge_cnt = 0;
    for (int i = 0; i < n - 1; ++i) {
        const auto [x1, y1, z1, id1] = tmp[i];
        const auto [x2, y2, z2, id2] = tmp[i + 1];
        edge_y[edge_cnt++] = {abs(y1 - y2), id1, id2};
    }
    sort(edge_y, edge_y + edge_cnt);

    sort(tmp, tmp + n, compare_z);
    edge_cnt = 0;
    for (int i = 0; i < n - 1; ++i) {
        const auto [x1, y1, z1, id1] = tmp[i];
        const auto [x2, y2, z2, id2] = tmp[i + 1];
        edge_z[edge_cnt++] = {abs(z1 - z2), id1, id2};
    }
    sort(edge_z, edge_z + edge_cnt);

    const int len = n - 1;
    const int INF = 1e9;
    while (cnt < n - 1) {
        int cost_x = INF, x1 = -1, x2 = -1;
        int cost_y = INF, y1 = -1, y2 = -1;
        int cost_z = INF, z1 = -1, z2 = -1;

        if (idx_x < len) tie(cost_x, x1, x2) = edge_x[idx_x];
        if (idx_y < len) tie(cost_y, y1, y2) = edge_y[idx_y];
        if (idx_z < len) tie(cost_z, z1, z2) = edge_z[idx_z];

        if (cost_x <= cost_y && cost_x <= cost_z) {
            idx_x++;
            if (uni(x1, x2)) {
                ans += cost_x;
                cnt++;
            }
        } else if (cost_y <= cost_x && cost_y <= cost_z) {
            idx_y++;
            if (uni(y1, y2)) {
                ans += cost_y;
                cnt++;
            }
        } else {
            idx_z++;
            if (uni(z1, z2)) {
                ans += cost_z;
                cnt++;
            }
        }
    }

    cout << ans;

    return 0;
}