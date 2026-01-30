#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, s, en = 0, ans = 100000000;
    long long sum = 0;
    cin >> n >> s;

    int arr[n];
    for (int i = 0; i < n; ++i) cin >> arr[i];

    for (int st = 0; st < n; ++st) {
        while (en < n && sum < s) sum += arr[en++];
        if (sum >= s) ans = min(ans, en - st);
        sum -= arr[st];
    }

    if (ans == 100000000) cout << 0;
    else cout << ans;

    return 0;
}