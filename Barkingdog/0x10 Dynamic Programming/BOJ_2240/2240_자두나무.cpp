#include <iostream>

using namespace std;

int arr[1001][32];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t, w, a, now, ans = 0;
    cin >> t >> w;
    for (int i = 1; i <= t; ++i) {
        cin >> a;
        for (int j = 1; j <= w + 1; ++j) {
            now = j % 2 == 1 ? 1 : 2;
            if(now == a) arr[i][j] = max(arr[i-1][j], arr[i-1][j-1]) + 1;
            else arr[i][j] = max(arr[i-1][j], arr[i-1][j-1]);
        }
    }
    for (int i = 1; i <= w + 1; ++i) ans = max(ans, arr[t][i]);
    cout << ans;
    return 0;
}