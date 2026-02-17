#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, sum = 0;
    cin >> n;

    vector<vector<int>> arr(n + 1, vector<int>(n + 1));
    vector<vector<bool>> check(n + 1, vector<bool>(n + 1, false));

    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j){
            cin >> arr[i][j];
            if (i < j) sum += arr[i][j];
        }


    for (int k = 1; k <= n; ++k)
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j){
                if (i >= j || k == i || k == j) continue;
                if (arr[i][j] > arr[i][k] + arr[k][j]){
                    cout << -1;
                    return 0;
                }
                if (!check[i][j] && arr[i][j] == arr[i][k] + arr[k][j]){
                    sum -= arr[i][j];
                    check[i][j] = true;
                }
            }

    cout << sum;

    return 0;
}