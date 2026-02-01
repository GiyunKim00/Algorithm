#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, k, ans = 0, cnt = 0, check = 0, st = 0, en = 0;

    cin >> n >> k;

    int arr[n];

    for (int i = 0; i < n; ++i) cin >> arr[i];

    while (en < n){
        if (arr[en++] % 2 == 0) cnt++;
        else check++;

        ans = max(ans, cnt);

        while (check > k){
            if (arr[st++] % 2 != 0) check--;
            else cnt--;
        }
    }

    cout << ans;

    return 0;
}