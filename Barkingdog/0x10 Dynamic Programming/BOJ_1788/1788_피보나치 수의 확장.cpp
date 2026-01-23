#include <iostream>

using namespace std;

int dp[1000001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, sign, idx = 2;
    cin >> n;

    dp[1] = 1;

    if (n >= 0) sign = (n > 0) ? 1 : 0;
    else if (n % 2 == 0) sign = -1;
    else sign = 1;

    n = abs(n);

    for (; idx <= n; ++idx) dp[idx] = (dp[idx - 1] + dp[idx - 2]) % 1000000000;

    cout << sign << "\n" << dp[n];
    return 0;
}