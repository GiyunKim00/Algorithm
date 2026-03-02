#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n, amount;
        cin >> n;
        vector<int> coin(n);
        for (int i = 0; i < n; ++i) cin >> coin[i];
        cin >> amount;

        vector<int> dp(amount + 1, 0);
        dp[0] = 1;

        for (const int &c : coin)
            for (int j = c; j <= amount; ++j)
                dp[j] += dp[j - c];

        cout << dp[amount] << "\n";
    }
}