#include <iostream>
#include <vector>

using namespace std;
int dp[10001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, k;
    cin >> n >> k;
    int arr[n];
    for (int i = 0; i < n; ++i) cin >> arr[i];

    dp[0] = 1;

    /**
     * 순열 문제로, 로직을 찾고자 한참 헤맸음.
     * 동전을 바깥 루프에, 세는 로직을 안쪽 루프에 두어야 조합, 반대로 둘 시 순열.
     * 이 문제에서는 조합(중복 X)을 원했음.
     */
    for(auto i : arr) {
        for(int j = i; j<=k; j++) dp[j] += dp[j-i];
    }


    cout << dp[k];

    return 0;
}