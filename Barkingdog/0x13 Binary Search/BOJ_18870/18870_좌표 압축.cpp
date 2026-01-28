#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<int> ans;

int binary_search(int t) {
    int s = 0, e = ans.size() - 1;
    while (s <= e) {
        int mid = (s + e) / 2;
        if (ans[mid] == t) return mid;
        if (ans[mid] < t) s = mid + 1;
        else e = mid - 1;
    }

    return s;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
        ans.push_back(arr[i]);
    }
    sort(ans.begin(), ans.end());
    ans.erase(unique(ans.begin(), ans.end()), ans.end());

    // for (auto i: arr) cout << binary_search(i) << " ";
    for (auto i : arr) cout << lower_bound(ans.begin(), ans.end(), i) - ans.begin() << " ";
    return 0;
}
