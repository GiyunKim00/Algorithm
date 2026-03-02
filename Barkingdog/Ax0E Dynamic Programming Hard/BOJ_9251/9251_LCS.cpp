#include <iostream>

using namespace std;

int dp[1001][1001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string a, b;
    cin >> a >> b;

    const int a_size = a.size(), b_size = b.size();

    for (int i = 1; i <= a_size; ++i) {
        for (int j = 1; j <= b_size; ++j) {
            if (a[i-1] == b[j-1]) dp[i][j] = dp[i-1][j-1] + 1;
            else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }

    cout << dp[a_size][b_size];

    return 0;
}