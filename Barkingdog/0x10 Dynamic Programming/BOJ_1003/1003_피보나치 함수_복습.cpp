#include <iostream>

using namespace std;

int dp[41][2];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t, last_idx = 2;
    cin >> t;

    dp[0][0] = dp[1][1] = 1;

    while (t--) {
        int n;
        cin >> n;

        for (int i = last_idx; i <= n; ++i)
            for (int j = 0; j < 2; ++j)
                dp[i][j] = dp[i - 2][j] + dp[i - 1][j];

        last_idx = max(last_idx, n + 1);
        cout << dp[n][0] << " " << dp[n][1] << "\n";
    }

    return 0;
}