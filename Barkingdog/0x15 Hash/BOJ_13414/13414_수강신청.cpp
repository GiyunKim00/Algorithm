#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int k, l, cnt = 0;
    cin >> k >> l;
    unordered_map<string, int> m;
    vector<string> v(l);

    for (int i = 0; i < l; ++i) {
        string a;
        cin >> a;
        m[a] = i;
    }

    for (auto &i: m) v[i.second] = i.first;

    for (int i = 0; i < l && cnt < k; ++i) {
        if (!v[i].empty()) {
            cout << v[i] << "\n";
            cnt++;
        }
    }

    return 0;
}