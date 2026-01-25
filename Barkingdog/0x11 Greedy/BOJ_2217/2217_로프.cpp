#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(int &a, int &b) {
    return a > b;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, ans;
    cin >> n;

    vector<int> arr(n);

    for (int i = 0; i < n; ++i) cin >> arr[i];

    sort(arr.begin(), arr.end(), compare);

    ans = arr[0];

    for (int i = 1; i < n; ++i) ans = max(ans, arr[i] * (i + 1));

    cout << ans;

    return 0;
}