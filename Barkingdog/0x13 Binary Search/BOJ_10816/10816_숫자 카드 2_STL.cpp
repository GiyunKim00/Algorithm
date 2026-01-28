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

    int n,m, a;
    cin >> n;
    vector<int> arr(n);

    for (int i = 0; i < n; ++i) cin >> arr[i];

    sort(arr.begin(), arr.end());

    cin >> m;

    for (int i = 0; i < m; ++i) {
        cin >> a;
        cout << upper_bound(arr.begin(), arr.end(), a) - lower_bound(arr.begin(), arr.end(), a) << "\n";
    }

    return 0;
}