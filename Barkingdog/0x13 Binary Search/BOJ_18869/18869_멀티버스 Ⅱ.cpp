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
    vector<vector<int> > arr(m, vector<int>(n));
    vector<vector<int> > ans(m, vector<int>(n));
    vector<vector<int> > v(m, vector<int>(n));

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> arr[i][j];
            ans[i][j] = arr[i][j];
        }
    }

    for (int i = 0; i < m; ++i) sort(ans[i].begin(), ans[i].end());

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) v[i][j] = lower_bound(ans[i].begin(), ans[i].end(), arr[i][j]) - ans[i].begin();
    }

    for (int i = 0; i < m - 1; ++i) {
        for (int j = i + 1; j < m; ++j) {
            bool check = true;
            for (int k = 0; k < n; ++k) if (v[i][k] != v[j][k]) {
                check = false;
                break;
            }
            if (check) sum++;
        }
    }

    cout << sum;

    return 0;
}