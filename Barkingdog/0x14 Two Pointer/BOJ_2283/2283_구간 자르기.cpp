#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int arr[1000002];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k, r = 0, sum = 0, s = 0, e = 0;
    cin >> n >> k;

    for (int i = 0; i<n; ++i) {
        int a, b;
        cin >> a >> b;
        arr[a]++;
        arr[b]--;
        r = max(r, b);
    }
    r++;

    for (int i= 0; i<r; ++i) {
        sum += arr[i];
        arr[i] = sum;
    }

    sum = 0;

    while (e<r) {
        if (sum < k) sum += arr[e++];
        else if (sum > k) sum -= arr[s++];
        else {
            cout << s << " " << e;
            return 0;
        }
    }

    cout << "0 0";
    return 0;
}