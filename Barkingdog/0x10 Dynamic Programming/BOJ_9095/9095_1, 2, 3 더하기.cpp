#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t, n;
    cin >> t;

    while (t--) {
        cin >> n;
        vector<int> ans(n + 1, 0);
        ans[0] = ans[1] = 1;
        for (int i = 2; i <= n; ++i) {
            if (ans[i - 1]) ans[i] += ans[i-1];
            if (i - 2 >= 0 && ans[i - 2]) ans[i] += ans[i-2];
            if (i - 3 >= 0 && ans[i - 3]) ans[i] += ans[i-3];
        }
        cout << ans[n] << "\n";
    }

    return 0;
}