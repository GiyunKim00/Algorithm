#include <iostream>

using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, t;
    cin >> n;

    while (n--) {
        cin >> t;
        int arr[2][t];
        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < t; ++j) cin >> arr[i][j];
        }

        if(t>1){
            arr[0][1] += arr[1][0];
            arr[1][1] += arr[0][0];

            for (int i = 2; i < t; ++i) {
                arr[0][i] += max(arr[1][i - 1], arr[1][i - 2]);
                arr[1][i] += max(arr[0][i - 1], arr[0][i - 2]);
            }
        }

        cout << max(arr[0][t-1], arr[1][t-1]) << "\n";
    }
    return 0;
}