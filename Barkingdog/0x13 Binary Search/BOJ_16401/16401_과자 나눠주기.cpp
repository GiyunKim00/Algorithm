#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int m, n, mav_value = 0;
vector<int> arr;

int bs() {
    int s = 1, e = mav_value, mid, sum, ans = 0;
    while (s <= e) {
        sum = 0;
        mid = (s + e) / 2;
        for (auto i: arr) sum += i / mid;
        if (sum >= m) {
            ans = mid;
            s = mid + 1;
        } else e = mid - 1;
    }

    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;

    cin >> m >> n;

    for (int i = 0; i < n; ++i) {
        cin >> t;
        mav_value = max(mav_value, t);
        arr.push_back(t);
    }

    sort(arr.begin(), arr.end());

    cout << bs();

    return 0;
}
