#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, k, ans = 0;

    cin >> n >> k;

    int arr[n];

    for (int i = 0; i < n; ++i) cin >> arr[i];

    for (int st = 0; st < n; ++st){
        if (arr[st] % 2 != 0) continue;
        int cnt = 1, check = 0, en = st + 1;
        while (check <= k && en < n){
            if (arr[en] % 2 == 0) cnt++;
            else check++;
            en++;
        }
        ans = max(ans, cnt);
    }

    cout << ans;

    return 0;
}