#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, r;
    cin >> n >> m >> r;

    vector<vector<int> > arr(n + 1, vector<int>(n + 1, 1e9));
    int item[n + 1], ans = 0;
    for (int i = 1; i <= n; ++i) cin >> item[i];

    while (r--) {
        int a, b, cost;
        cin >> a >> b >> cost;
        arr[a][b] = min(arr[a][b], cost);
        arr[b][a] = min(arr[b][a], cost);
    }

    for (int i = 1; i <= n; ++i) arr[i][i] = 0;

    for (int k = 1; k <= n; ++k) {
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (arr[i][j] > arr[i][k] + arr[k][j]) arr[i][j] = arr[i][k] + arr[k][j];
            }
        }
    }

    for (int i = 1; i <= n; ++i) {
        int sum = 0;
        for (int j = 1; j <= n; ++j) if (arr[i][j] <= m) sum += item[j];
        ans = max(sum, ans);
    }

    cout << ans;

    return 0;
}