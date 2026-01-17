#include <iostream>

using namespace std;

long long int arr[91][2];

int main() {
    int n;
    cin >> n;
    arr[0][1] = 1;
    for (int i = 1; i < n; ++i) {
        arr[i][0] = arr[i - 1][0] + arr[i - 1][1];
        arr[i][1] = arr[i - 1][0];
    }

    cout << arr[n - 1][0] + arr[n - 1][1];

    return 0;
}