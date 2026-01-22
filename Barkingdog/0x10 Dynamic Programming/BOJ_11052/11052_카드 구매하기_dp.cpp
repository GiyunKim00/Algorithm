#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int dp[1001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    vector<int> arr(n + 1);

    for (int i = 1; i <= n; ++i) {
        cin >> arr[i];
        dp[i] = 0;
    }

    dp[1] = arr[1];

    for (int i = 2; i <= n; ++i) {
        for (int j = 1; j <= i; ++j) dp[i] = max(dp[i], dp[i - j] + arr[j]);
    }

    cout << dp[n];

    return 0;
}