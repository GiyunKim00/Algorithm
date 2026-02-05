#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    n *= n;
    vector<int> arr(n);

    for (int i = 0; i < n; ++i)cin >> arr[i];
    sort(arr.begin(), arr.end());
    cout << arr[n - sqrt(n)];
}