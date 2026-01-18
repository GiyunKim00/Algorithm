#include <iostream>

using namespace std;

struct counsel {
    int time;
    int pay;
};

counsel arr[1500001];
long long dp[1500002];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    long long int ans = 0;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i].time >> arr[i].pay;

    }

    /**
     * 오늘(i) 수업을 하는지, 안 하는지임.
     * 오늘 한다면? 오늘 함으로써 며칠 간 상담을 할 것이고, 그 상담이 끝난 날 또 다른 상담을 시작하게 될 것. 그 때의 수익을 합산한다.
     * 해당 값과 그냥 상담 안 하고 내일 상담할 돈과의 최댓값을 계산한다.
     * 만약 오늘 상담하지 않는다면? 내일 상담함으로써 벌어들일 수익이 앞으로의 최대 수익이 될 것.
     */
    for (int i = n - 1; i >= 0; --i) {
        if (arr[i].time + i <= n) dp[i] = max(dp[i + 1], arr[i].pay + dp[i + arr[i].time]);
        else dp[i] = dp[i + 1];
    }

    cout << dp[0];
    return 0;
}