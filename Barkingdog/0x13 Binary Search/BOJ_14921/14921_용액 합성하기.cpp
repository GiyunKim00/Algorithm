#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int n;
long long int ans = LLONG_MAX;
vector<long long int> arr;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> n;

    for (int i =0; i<n; ++i) {
        cin >> t;
        arr.push_back(t);
    }

    sort(arr.begin(), arr.end());

    for (int i = 0; i < n; i++) {
        long long int target = -arr[i];
        auto it = lower_bound(arr.begin() + i + 1, arr.end(), target);

        if (it != arr.end() && abs(ans) > abs(arr[i] + *it)) ans = arr[i] + *it;

        if (it != arr.begin() + i + 1) {
            --it;
            if (abs(ans) > abs(arr[i] + *it)) ans = arr[i] + *it;
        }
    }

    cout << ans;

    return 0;
}