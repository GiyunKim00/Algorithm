#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t, n, m, k;
    cin >> t;

    while (t--) {
        cin >> n >> m;

        vector<int> a, b;
        int idx_a = n - 1, idx_b = m - 1, cnt = 0;

        for (int i = 0; i < n; ++i) {
            cin >> k;
            a.push_back(k);
        }

        for (int i = 0; i < m; ++i) {
            cin >> k;
            b.push_back(k);
        }

        sort(a.begin(), a.end());
        sort(b.begin(), b.end());

        while (idx_a >= 0 && idx_b >= 0) {

            if (a[idx_a] > b[idx_b]) {
                idx_a--;
                cnt += idx_b + 1;
            } else idx_b--;
        }

        cout << cnt << "\n";
    }

    return 0;
}