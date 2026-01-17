#include <iostream>

using namespace std;

int arr[1000001][2];
bool visit[1000001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;

    arr[1][1] = -1;
    for (int i = 2; i <= n; ++i) {
        arr[i][0] = arr[i - 1][0] + 1;
        arr[i][1] = i - 1;
        if (i % 2 == 0) {
            if (arr[i / 2][0] + 1 < arr[i][0]) {
                arr[i][0] = arr[i / 2][0] + 1;
                arr[i][1] = i / 2;
            }
        }
        if (i % 3 == 0) {
            if (arr[i / 3][0] + 1 < arr[i][0]) {
                arr[i][0] = arr[i / 3][0] + 1;
                arr[i][1] = i / 3;
            }
        }
    }
    cout << arr[n][0] << "\n" << n << " ";
    int t = n;
    while (arr[t][1] != -1) {

        cout << arr[t][1] << " ";
        t = arr[t][1];
    }
}