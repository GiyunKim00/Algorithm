#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int n, m;
vector<int> arr;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t, ans = INT_MAX;

    cin >> n >> m;

    for (int i = 0; i < n; ++i) {
        cin >> t;
        arr.push_back(t);
    }

    sort(arr.begin(), arr.end());

    int en = 0;
    for (int st = 0; st < n; ++st) {
        while (en < n && arr[en] - arr[st] < m) en++;
        if (en == n) break;
        ans = min(ans, arr[en] - arr[st]);
    }

    cout << ans;

    return 0;
}