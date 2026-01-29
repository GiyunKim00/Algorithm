#include <iostream>
#include <vector>

using namespace std;

int n, m, max_value;
vector<int> arr;

long long int bs() {
    int s = 1, e = max_value;
    long long int ans = 0;
    while (s <= e) {
        long long int sum = 0;
        int mid = (s + e) / 2;
        for (auto i: arr) if (i > mid) sum += i - mid;
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

    cin >> n >> m;

    for (int i = 0; i < n; ++i) {
        cin >> t;
        max_value = max(t, max_value);
        arr.push_back(t);
    }

    cout << bs();

    return 0;
}