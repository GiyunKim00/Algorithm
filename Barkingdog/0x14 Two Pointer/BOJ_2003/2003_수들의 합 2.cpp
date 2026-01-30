#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m, e = 0, ans = 0, sum = 0;
    cin >> n >> m;
    int arr[n];

    for (int i = 0; i < n; ++i) cin >> arr[i];

    for (int s = 0; s < n; ++s) {
        while (e < n && sum < m) sum += arr[e++];
        if (sum == m) ans++;
        sum -= arr[s];
    }

    cout << ans;

    return 0;
}