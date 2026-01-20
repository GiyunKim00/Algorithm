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

    /**
     * 우리가 고려해야 할 것은 2가지로, n이 본인 좌석에 앉는 지, n-1의 자리에 앉는 지이다.
     * 본인 좌석에 앉는다면, n-1까지 잘 앉는 경우의 수를 구하면 되고, n-1에 앉는다면 n-2까지 잘 앉는 경우의 수를 구하면 된다.
     * 나의 경우 좌석이 1개일 때부터 5개까지의 경우의 수를 구해본 뒤 점화식을 유도해낸 케이스이다.
     * 점화식을 더 잘 구할 수 있도록 공부하자.
     */
    for (int i = 3; i <= max_length; ++i) dp[i] = dp[i - 1] + dp[i - 2];

    for (auto i: arr) ans *= dp[i];

    cout << ans;
    return 0;
}