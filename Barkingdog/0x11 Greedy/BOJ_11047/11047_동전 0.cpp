#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, k, cnt = 0;
    cin >> n >> k;

    int arr[n];

    while (--n >= 0) cin >> arr[n];

    for(auto i : arr) {
        cnt += k / i;
        k %= i;
        if(k == 0) break;
    }

    cout << cnt;

    return 0;
}