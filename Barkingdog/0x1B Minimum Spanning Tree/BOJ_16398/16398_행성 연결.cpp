#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Edge의 간선 개수는 Node에 비례하는데(n(n-1)/2.), i<j만 넣어도 간선 개수는 1000*999/2 ==499,500개.
 * 만약 i<j가 아닌, 통째로 넣는다면 n*n만큼이 필요.
 */
vector<int> p(1001, -1);
tuple<int, int, int> edge[499501];

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

    int n, edge_cnt = 0, cnt = 0;
    long long ans = 0;
    cin >> n;

    for (int i = 1; i <= n; ++i){
        for (int j = 1; j <= n; ++j){
            int a;
            cin >> a;
            if (i < j) edge[edge_cnt++] = {a, i, j};
        }
    }

    sort(edge, edge + edge_cnt);

    for (int i = 0; i < edge_cnt && cnt < n - 1; ++i){
        int cost, a, b;
        tie(cost, a, b) = edge[i];
        if (!uni(a, b)) continue;
        ans += cost;
        cnt++;
    }

    cout << ans;

    return 0;
}