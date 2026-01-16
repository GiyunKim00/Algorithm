#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

bool compare(pair<int, pair<int, int>> &a, pair<int, pair<int, int>> &b) {
    if (a.second.first == b.second.first) return a.second.second < b.second.second;
    return a.second.first > b.second.first;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, c, cnt = 0;
    map<int, pair<int, int>> m;
    cin >> n >> c;

    while (n--) {
        cin >> c;
        m[c].first++;
        if (m[c].first == 1) m[c].second = cnt++;
    }
    vector<pair<int, pair<int, int>>> ans(m.begin(), m.end());
    sort(ans.begin(), ans.end(), compare);

    for (auto i: ans) {
        for (int j = 0; j < i.second.first; ++j) cout << i.first << " ";
    }

    return 0;
}