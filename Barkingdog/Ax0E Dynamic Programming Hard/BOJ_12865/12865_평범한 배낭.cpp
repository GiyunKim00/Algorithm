#include <iostream>

using namespace std;

int dp[101][100001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, max_weight;
    cin >> n >> max_weight;

    /**
     * 물건을 쪼갤 수 없는 Knapsack이므로 DP로 풀이함. 만약 쪼갤 수 있다면 Greedy임.
     * 만약 j가 weight보다 작다면 이전 것을 계속 가져옴.
     * j가 weight 이상이면 위의 것을 가져오는 것과, 바로 전까지 담은 item cost 총합 + 현재 담을 수 있는 item의 cost 중 큰 것을 선택.
     */
    for (int i = 1; i <= n; ++i) {
        int weight, cost;
        cin >> weight >> cost;

        for (int j = 0; j <= max_weight; ++j) {
            dp[i][j] = dp[i - 1][j];
            if (j >= weight) dp[i][j] = max(dp[i][j], dp[i - 1][j - weight] + cost);
        }
    }

    cout << dp[n][max_weight];

    return 0;
}