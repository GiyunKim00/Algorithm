#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<int> arr;

int upper_bound(int t) {
    int s = 0, e = n;
    while (s < e) {
        int mid = (s + e) / 2;
        if (arr[mid] > t) e = mid;
        else s = mid + 1;
    }

    return s;
}

int lower_bound(int t) {
    int s = 0, e = n;
    while (s < e) {
        int mid = (s + e) / 2;
        if (arr[mid] >= t) e = mid;
        else s = mid + 1;
    }

    return s;
}

int binary_search(int t) {
    return upper_bound(t) - lower_bound(t);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int m, a;

    cin >> n;

    for (int i = 0; i < n; ++i) {
        cin >> a;
        arr.push_back(a);
    }

    sort(arr.begin(), arr.end());

    cin >> m;

    for (int i = 0; i < m; ++i) {
        cin >> a;
        cout << binary_search(a) << "\n";
    }

    return 0;
}
