#include <iostream>
#include <vector>

using namespace std;
int dp[41];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m, t, last_idx = 0, max_length = 1, ans = 1;
    vector<int> arr;
    cin >> n >> m;
    dp[1] = 1;
    dp[2] = 2;

    for (int i = 0; i < m; ++i) {
        cin >> t;
        if (t - last_idx - 1 > 0) arr.push_back(t - last_idx - 1);
        max_length = max(t - last_idx - 1, max_length);
        last_idx = t;
    }

    if (n - last_idx > 1) {
        arr.push_back(n - last_idx);
        max_length = max(arr.back(), max_length);
    }

    for (int i = 3; i <= max_length; ++i) dp[i] = dp[i - 1] + dp[i - 2];

    for (auto i: arr) ans *= dp[i];

    cout << ans;
    return 0;
}