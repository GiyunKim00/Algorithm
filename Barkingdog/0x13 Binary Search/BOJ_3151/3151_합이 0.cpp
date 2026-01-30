#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<int> arr;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t, ans = 0;

    cin >> n;

    for (int i = 0; i < n; ++i) {
        cin >> t;
        arr.push_back(t);
    }

    sort(arr.begin(), arr.end());

    /**
     * equal_range() // STL algorithm
     * 정렬된 구간 [first, last) 에서
     * - value 이상이 처음 등장하는 위치 (lower_bound)
     * - value 보다 큰 값이 처음 등장하는 위치 (upper_bound)
     * 각각을 반환하는 메서드.
     */
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            auto k = equal_range(arr.begin() + j + 1, arr.end(), -(arr[i] + arr[j]));
            ans += k.second - k.first;
        }
    }

    cout << ans;

    return 0;
}