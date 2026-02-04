#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int ans = 0;
    string s, e, se, k, a, b;
    cin >> s >> e >> se;

    unordered_map<string, pair<int, int> > m;

    while (cin >> a >> b) {
        if (a <= s) m[b].first++;
        else if (a >= e && a <= se) m[b].second++;
    };

    for (const auto &[fst, snd]: m) if (snd.first > 0 && snd.second > 0) ans++;

    cout << ans;

    return 0;
}