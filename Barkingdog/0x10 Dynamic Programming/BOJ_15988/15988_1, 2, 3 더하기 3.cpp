#include <iostream>
#include <vector>

using namespace std;

int arr[1000001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t, n, idx = 3;
    cin >> t;

    while (t--) {
        cin >> n;
        arr[0] = arr[1] = 1, arr[2] = 2;
        for (int i = idx; i <= n; ++i, ++idx) arr[i] = arr[i - 1] + (arr[i] + arr[i - 2]) % 1000000009 +
                                                       (arr[i] + arr[i - 3]) % 1000000009;

        cout << arr[n] << "\n";
    }

    return 0;
}