#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int n;
vector<int> arr;

bool binary_search(const int t) {
    int s = 0, e = n - 1;

    while (s <= e) {
        const int mid = (s + e) / 2;
        if (arr[mid] == t) return true;
        if (arr[mid] < t) s = mid + 1;
        else e = mid - 1;
    }

    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int a, m;
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