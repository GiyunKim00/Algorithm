#include <iostream>
#include <queue>

using namespace std;
int n, m, limit;

int dfs(const vector<int> *arr, vector<bool> &visit, const int idx) {
    int cnt = 1;
    visit[idx] = true;

    for (const auto i: arr[idx]) {
        if (visit[i]) continue;
        cnt += dfs(arr, visit, i);
    }
    return cnt;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int cnt = 0;
    cin >> n >> m;
    limit = (n + 1) / 2;
    vector<int> arr_asc[n + 1], arr_des[n + 1];

    while (m--) {
        int a, b;
        cin >> a >> b;
        arr_asc[b].push_back(a);
        arr_des[a].push_back(b);
    }

    for (int i = 1; i <= n; ++i) {
        vector<bool> visit(n + 1, false);
        if (dfs(arr_asc, visit, i) - 1 >= limit || dfs(arr_des, visit, i) - 1 >= limit) cnt++;
    }

    cout << cnt;
    return 0;
}