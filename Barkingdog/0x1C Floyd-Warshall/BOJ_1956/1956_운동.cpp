#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int v, e, ans = 1e9;
    cin >> v >> e;
    vector<vector<int>> arr(v + 1, vector<int>(v + 1, 1e9));

    while (e--){
        int a, b, cost;
        cin >> a >> b >> cost;
        arr[a][b] = min(arr[a][b], cost);
    }

    for (int i = 1; i <= v; ++i) arr[i][i] = 0;

    for (int k = 1; k <= v; ++k)
        for (int i = 1; i <= v; ++i)
            for (int j = 1; j <= v; ++j)
                arr[i][j] = min(arr[i][j], arr[i][k] + arr[k][j]);

    for (int i = 1; i <= v; ++i){
        for (int j = 1; j <= v; ++j){
            if (i == j || arr[i][j] == 1e9 || arr[j][i] == 1e9) continue;
            ans = min(ans, arr[i][j] + arr[j][i]);
        }
    }
    if (ans == 1e9) cout << -1;
    else cout << ans;

    return 0;
}
