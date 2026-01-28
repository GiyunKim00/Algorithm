#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<int> arr, ans;

bool binary_search(int t) {
    int s = 0, e = ans.size() - 1, mid;

    while (s<=e) {
        mid = (s + e) / 2;
        if (ans[mid] == t) return true;
        if (ans[mid] < t) s = mid + 1;
        else e = mid - 1;
    }

    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int k;
    cin >> n;


    for (int i = 0; i < n; ++i) {
        cin >> k;
        arr.push_back(k);
    }

    for (int i = 0; i < n; i++)
        for (int j = i; j < n; j++)
            ans.push_back(arr[i] + arr[j]);

    sort(ans.begin(), ans.end());
    sort(arr.begin(), arr.end());

    for (int i = n - 1; i >= 0; i--) {
        for (int j = 0; j < n; ++j) {
            if (binary_search(arr[i] - arr[j])) {
                cout << arr[i];
                return 0;
            }
        }
    }

    return 0;
}