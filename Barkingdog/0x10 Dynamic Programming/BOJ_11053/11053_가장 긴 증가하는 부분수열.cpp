#include <iostream>

using namespace std;

int arr[1001], dp[1001];

int main() {
    int n, ans = 0;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
        dp[i] = 1;

        for (int j = 0; j < i; ++j)
            if (arr[j] < arr[i]) dp[i] = max(dp[i], dp[j] + 1);

        ans = max(dp[i], ans);
    }

    cout << ans;

    return 0;
}