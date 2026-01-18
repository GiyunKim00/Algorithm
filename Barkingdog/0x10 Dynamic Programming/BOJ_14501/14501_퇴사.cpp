#include <iostream>

using namespace std;

struct counsel {
    int time;
    int pay;
};

counsel arr[15];
int dp[15];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, ans = 0;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i].time >> arr[i].pay;
        /**
         * 해당 일자의 상담을 반드시 한다고 가정 시, 해당 상담이 상담 종료 기간 내 가능한 지 체크
         */
        if (i + arr[i].time <= n) {
            dp[i] = arr[i].pay;

            /**
             * i번째 상담이 포함되었을 시, 이전 일자 중 가장 이득이 크며 i 상담과 겹치지 않는 상담을 고름.
             */
            for (int j = i - 1; j >= 0; --j) {
                if (arr[j].time + j <= i) {
                    dp[i] = max(dp[i], dp[j] + arr[i].pay);
                }
            }

            ans = max(dp[i], ans);
        }
    }

    cout << ans;
    return 0;
}