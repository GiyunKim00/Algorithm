#include <iostream>

using namespace std;

int arr[41][2];

int main() {
    int t, a;
    cin >> t;
    arr[1][1] = 1;
    arr[0][0] = 1;
    while (t--) {
        cin >> a;
        for (int i = 2; i <= a; i++) {
            arr[i][0] = arr[i - 2][0] + arr[i - 1][0];
            arr[i][1] = arr[i - 2][1] + arr[i - 1][1];
        }
        cout << arr[a][0] << " " << arr[a][1] << "\n";
    }

    return 0;
}