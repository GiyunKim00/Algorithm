#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t, n;
    string a, b;
    cin >> t;

    while (t--) {
        cin >> n;
        unordered_map<string, int> m;
        int ans = 1;
        for (int i = 0; i < n; ++i) {
            cin >> a >> b;
            m[b]++;
        }

        for (auto &i: m) ans *= (i.second + 1);
        cout << ans - 1 << "\n";
    }

    return 0;
}