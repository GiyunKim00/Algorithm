#include <iostream>

using namespace std;

int arr[1001][3];
int ans[1001][3];

int main() {
    int n, sum = 0;
    cin >> n;

    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < 3; ++j) cin >> arr[i][j];
    }
    for(int i = 0; i<3; ++i) ans[1][i] = arr[1][i];

    for (int i = 2; i <= n; ++i) {
        ans[i][0] = min(ans[i-1][1], ans[i-1][2]) + arr[i][0];
        ans[i][1] = min(ans[i-1][0], ans[i-1][2]) + arr[i][1];
        ans[i][2] = min(ans[i-1][0], ans[i-1][1]) + arr[i][2];
    }

    if(ans[n][0] < ans[n][1]) cout << min(ans[n][0], ans[n][2]);
    else cout << min(ans[n][1], ans[n][2]);

    return 0;
}