#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k, cnt = 0;
    cin >> n >> k;
    int arr[n];
    while (--n >= 0) cin >> arr[n];

    for (const auto i: arr) {
        cnt += k / i;
        k %= i;
    }

    cout << cnt;
    return 0;
}