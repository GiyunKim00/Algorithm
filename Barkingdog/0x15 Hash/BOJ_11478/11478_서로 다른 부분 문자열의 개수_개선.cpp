#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string str;
    cin >> str;
    int n = str.length(), ans = 0;

    for (int len = 1; len <= n; len++) {
        vector<string> t;
        t.reserve(n - len + 1);

        for (int i = 0; i <= n - len; i++) t.push_back(str.substr(i, len));

        sort(t.begin(), t.end());

        int cnt = 1;
        for (size_t i = 0; i < t.size() - 1; ++i) if (t[i] != t[i + 1]) cnt++;

        if (t.empty()) cnt = 0;

        ans += cnt;
    }
    cout << ans;
}