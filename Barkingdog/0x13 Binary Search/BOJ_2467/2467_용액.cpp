#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int n;
vector<int> arr;

void bs() {
    long long ans = LLONG_MAX;
    int x, y;

    for (int i = 0; i < n; i++) {
        int target = -arr[i];

        int s = i + 1, e = n - 1;
        while (s <= e) {
            int mid = (s + e) / 2;
            long long sum = arr[i] + arr[mid];

            if (llabs(sum) < ans) {
                ans = llabs(sum);
                x = arr[i];
                y = arr[mid];
            }

            if (arr[mid] < target) s = mid + 1;
            else e = mid - 1;
        }
    }

    if (x > y) cout << y << " " << x;
    else cout << x << " " << y;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;

    cin >> n;

    for (int i = 0; i < n; ++i) {
        cin >> t;
        arr.push_back(t);
    }

    sort(arr.begin(), arr.end());

    bs();

    return 0;
}