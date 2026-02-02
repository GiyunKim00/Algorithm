#include <iostream>

using namespace std;

int visit[100001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k, s = 0, e = 0, ans = 0, sum = 0;

    cin >> n >> k;
    int arr[n];

    for (int i = 0; i < n; ++i) cin >> arr[i];

    while (e < n){
        visit[arr[e]]++;
        sum++;

        while (visit[arr[e]] > k){
            visit[arr[s++]]--;
            sum--;
        }
        e++;
        ans = max(ans, sum);
    }

    cout << ans;

    return 0;
}