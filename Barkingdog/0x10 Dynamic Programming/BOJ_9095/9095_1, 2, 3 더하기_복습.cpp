#include <iostream>

using namespace std;

int dp[11];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);


    int t, last_idx = 1;

    cin >> t;
    dp[0] = dp[1] = 1;

    while (t--) {
        int n;
        cin >> n;

        if (last_idx < n) {
            for (int i = last_idx + 1; i <= n; ++i) {
                dp[i] += dp[i - 1];
                if (i - 2 >= 0) dp[i] += dp[i - 2];
                if (i - 3 >= 0) dp[i] += dp[i - 3];
            }
            last_idx = n;
        }
        cout << dp[n] << "\n";
    }

    return 0;
}
