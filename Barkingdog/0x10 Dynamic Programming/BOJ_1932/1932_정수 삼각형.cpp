#include <iostream>

using namespace std;

int ans[501][501];
int arr[501];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, ans_cnt = 0;
    cin >> n;

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= i; ++j) cin >> arr[j];

        if (i == 1) ans[1][1] = arr[1];

        ans[i][1] = ans[i - 1][1] + arr[1];
        ans[i][i] = ans[i - 1][i - 1] + arr[i];

        for (int j = 2; j < i; ++j) ans[i][j] = max(ans[i - 1][j - 1] + arr[j], ans[i - 1][j] + arr[j]);
    }

    for (int i = 1; i <= n; ++i) ans_cnt = max(ans[n][i], ans_cnt);

    cout << ans_cnt;
}