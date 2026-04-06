#include <iostream>

using namespace std;

int stair[301], dp[301];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> stair[i];

    dp[1] = stair[1];
    dp[2] = stair[1] + stair[2];

    for (int i = 3; i <= n; ++i) dp[i] = max(dp[i-3] + stair[i-1], dp[i-2]) + stair[i];

    cout << dp[n];
    return 0;
}
