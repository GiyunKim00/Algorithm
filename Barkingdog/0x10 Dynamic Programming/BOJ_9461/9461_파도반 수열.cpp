#include <iostream>

using namespace std;

long long int arr[101];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t, n, idx = 4;
    cin >> t;
    arr[1] = arr[2] = arr[3] = 1;
    while (t--) {
        cin >> n;
        for (; idx <= n; ++idx) arr[idx] = arr[idx - 3] + arr[idx - 2];
        cout << arr[n] << "\n";
    }

    return 0;
}