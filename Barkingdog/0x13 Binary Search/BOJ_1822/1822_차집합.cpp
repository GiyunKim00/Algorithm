#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
vector<int> a, b;

bool bs(int t) {
    int s = 0, e = m - 1;

    while (s <= e) {
        int mid = (s + e) / 2;
        if (b[mid] == t) return true;
        if (b[mid] > t) e = mid - 1;
        else s = mid + 1;
    }

    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    vector<int> ans;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> t;
        a.push_back(t);
    }

    for (int i = 0; i < m; ++i) {
        cin >> t;
        b.push_back(t);
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    for (auto i : a) if (!bs(i)) ans.push_back(i);
    cout << ans.size() << "\n";
    for (auto i : ans) cout << i << " ";

    return 0;
}