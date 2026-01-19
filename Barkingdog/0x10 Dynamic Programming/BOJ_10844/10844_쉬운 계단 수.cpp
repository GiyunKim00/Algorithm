#include <iostream>

using namespace std;

int dp[101][10];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, sum = 0;

    cin >> n;
    for (int i = 1; i < 10; ++i) dp[1][i] = 1;

    for (int i = 2; i <= n; ++i) {
        dp[i][0] = dp[i - 1][1];
        dp[i][9] = dp[i - 1][8];
        for (int j = 1; j <= 8; ++j) dp[i][j] = (dp[i-1][j - 1] + dp[i-1][j + 1]) % 1000000000;
    }

    for(int i = 0; i<10; ++i) sum = (sum + dp[n][i]) % 1000000000;

    cout << sum;

    return 0;
}