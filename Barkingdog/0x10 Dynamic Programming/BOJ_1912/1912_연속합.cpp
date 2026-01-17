#include <iostream>
#include <vector>

using namespace std;
int arr[100002];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, k, ans = -1001, low = 0;
    cin >> n;

    for (int i = 1; i <= n; ++i) {
        cin >> k;
        arr[i] = arr[i - 1] + k;
        ans = max(arr[i] - low, ans);
        low = min(arr[i], low);
    }

    cout <<  ans;

    return 0;
}
