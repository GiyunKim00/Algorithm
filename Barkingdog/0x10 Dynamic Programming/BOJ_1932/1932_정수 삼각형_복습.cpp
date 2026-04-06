#include <iostream>

using namespace std;

int dp[500][500], arr[500];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, ans = 0;
    cin >> n >> dp[0][0];

    ans = dp[0][0];

    for (int i = 1; i < n; ++i) {
        int a;
        for (int j = 0; j <= i; ++j) {
            cin >> a;
            if (j == 0) dp[i][0] = dp[i - 1][0];
            else if (j == i) dp[i][j] = dp[i - 1][j - 1];
            else dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j]);
            dp[i][j] += a;
            if (dp[i][j] > ans) ans = dp[i][j];
        }
    }

    cout << ans;

    return 0;
}