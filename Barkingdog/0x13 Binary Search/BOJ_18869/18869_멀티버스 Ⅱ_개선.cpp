#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int m, n, sum = 0;
    cin >> m >> n;
    vector arr(m, vector<int>(n));
    vector ans(m, vector<int>(n));

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) cin >> arr[i][j];
    }

    for (int i = 0; i < m; ++i) {
        vector<int> tmp = arr[i];
        sort(tmp.begin(), tmp.end());

        for (int j = 0; j < n; ++j) ans[i][j] = lower_bound(tmp.begin(), tmp.end(), arr[i][j]) - tmp.begin();
    }


    for (int i = 0; i < m - 1; ++i) {
        for (int j = i + 1; j < m; ++j) {
            if (ans[i] == ans[j]) sum++;
        }
    }

    cout << sum;

    return 0;
}
