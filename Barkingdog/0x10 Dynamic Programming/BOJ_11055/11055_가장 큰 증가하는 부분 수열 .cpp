#include <iostream>

using namespace std;

int arr[1001];
int dp[1001];

int main() {
    int n, t, ans = 0;
    cin >> n;

    for (int i = 1; i <= n; ++i) {
        cin >> t;
        arr[i] = t;
        dp[i] = t;

        for (int j = 1; j < i; ++j)
            if (arr[j] < arr[i]) dp[i] = max(dp[i], dp[j] + arr[i]);

        ans = max(dp[i], ans);
    }

    cout << ans;
    return 0;
}