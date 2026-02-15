#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, k, best = 1e9;

    cin >> n >> m;

    vector<vector<int>> arr(n + 1, vector<int>(n + 1, 1e9));
    vector<int> ans;

    while (m--){
        int a, b, cost;
        cin >> a >> b >> cost;
        if (arr[a][b] > cost) arr[a][b] = cost;
    }

    for (int i = 1; i <= n; ++i) arr[i][i] = 0;

    cin >> k;
    vector<int> members(k + 1);

    for (int i = 1; i <= k; ++i)cin >> members[i];

    for (int t = 1; t <= n; ++t)
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j) if (arr[i][j] > arr[i][t] + arr[t][j]) arr[i][j] = arr[i][t] + arr[t][j];

    for (int i = 1; i <= n; ++i){
        int tmp = 0;
        for (int member = 1; member <= k; ++member){
            if (members[member] == i) continue;
            if (tmp < arr[members[member]][i] + arr[i][members[member]]) tmp = arr[members[member]][i] + arr[i][members[member]];
        }
        if (best > tmp){
            best = tmp;
            ans.clear();
            ans.push_back(i);
        }
        else if (best == tmp) ans.push_back(i);
    }

    for (const int x : ans) cout << x << ' ';

    return 0;
}