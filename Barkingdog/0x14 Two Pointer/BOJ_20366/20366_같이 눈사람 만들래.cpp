#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, ans = INT_MAX;
    cin >> n;
    vector<int> arr(n);

    for (int i = 0; i < n; ++i) cin >> arr[i];
    sort(arr.begin(), arr.end());

    for (int i = 0; i < n; ++i) {
        for (int j = i + 3; j < n; ++j) {
            int s = i + 1;
            int e = j - 1;

            int target = arr[i] + arr[j];

            while (s < e) {
                int cur = arr[s] + arr[e];
                ans = min(ans, abs(target - cur));

                if (cur < target) s++;
                else e--;
            }
        }
    }

    cout << ans;

    return 0;
}