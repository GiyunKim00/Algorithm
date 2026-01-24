#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, cnt = 1;
    while (true) {
        cin >> n;
        if (!n) break;

        int arr[n + 1][3];

        cin >> arr[0][0] >> arr[0][1] >> arr[0][2];
        cin >> arr[1][0] >> arr[1][1] >> arr[1][2];

        arr[1][0] += arr[0][1];
        arr[1][1] += min(arr[1][0], min(arr[0][1], arr[0][1] + arr[0][2]));
        arr[1][2] += min(arr[1][1], min(arr[0][1], arr[0][1] + arr[0][2]));

        for (int i = 2; i < n; ++i) {
            cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
            arr[i][0] += min(arr[i - 1][0], arr[i - 1][1]);
            arr[i][1] += min(arr[i][0], min(arr[i - 1][0], min(arr[i - 1][1], arr[i - 1][2])));
            arr[i][2] += min(arr[i][1], min(arr[i - 1][1], arr[i - 1][2]));
        }

        cout << cnt << ". " << arr[n - 1][1] << "\n";
        cnt++;
    }
    return 0;
}