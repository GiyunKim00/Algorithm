#include <iostream>

using namespace std;

int house[1000][3], dp[1000][3];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < 3; ++j)
            cin >> house[i][j];

    for (int j = 0; j < 3; ++j) dp[0][j] = house[0][j];

    for (int i = 1; i < n; ++i) {
        dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + house[i][0];
        dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + house[i][1];
        dp[i][2] = min(dp[i - 1][1], dp[i - 1][0]) + house[i][2];
    }

    const int ans = min(dp[n - 1][0], dp[n - 1][1]);
    cout << min(ans, dp[n - 1][2]);

    return 0;
}