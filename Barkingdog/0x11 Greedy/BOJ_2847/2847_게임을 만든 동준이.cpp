#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, max_value, ans = 0;
    cin >> n;
    int arr[n];

    for (int i = 0; i < n; ++i) cin >> arr[i];
    max_value = arr[--n];

    while (--n >= 0){
        int cnt = 0;
        if (max_value <= arr[n]){
            cnt = arr[n] - max_value + 1;
            arr[n] -= cnt;
            ans += cnt;
        }
        max_value = arr[n];
    }

    cout << ans;

    return 0;
}