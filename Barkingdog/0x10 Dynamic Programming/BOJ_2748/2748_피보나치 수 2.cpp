#include <iostream>

using namespace std;

long long int arr[91];

int main() {
    int n;
    cin >> n;
    arr[1] = arr[2] = 1;

    for (int i = 3; i <= n; ++i) arr[i] = arr[i - 1] + arr[i - 2];

    cout << arr[n];
    return 0;
}