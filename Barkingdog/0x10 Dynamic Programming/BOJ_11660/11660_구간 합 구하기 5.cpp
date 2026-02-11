#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, sum = 0;
    cin >> n >> m;

    vector<vector<int> > prefix_sum(n + 1, vector<int>(n + 1)), arr(n + 1, vector<int>(n + 1));

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> arr[i][j];
            sum += arr[i][j];
            prefix_sum[i][j] = sum;
        }
    }

    while (m--) {
        sum = 0;
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        for (; x1 <= x2; ++x1) sum += prefix_sum[x1][y2] - prefix_sum[x1][y1] + arr[x1][y1];
        cout << sum << "\n";
    }

    return 0;
}