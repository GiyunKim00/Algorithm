#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    multiset<int> bag;
    vector<pair<int, int>> gem;
    int n, k;
    long long int ans = 0;

    cin >> n >> k;
    gem.reserve(n);
    while (n--){
        int weight, value;
        cin >> weight >> value;
        gem.emplace_back(value, weight);
    }

    sort(gem.begin(), gem.end());

    for (int i = 0; i < k; ++i){
        int area;
        cin >> area;
        bag.insert(area);
    }

    for (auto it = gem.rbegin(); it != gem.rend(); ++it){
        auto i = bag.lower_bound(it->second);
        if (i == bag.end()) continue;
        ans += it->first;
        bag.erase(i);
    }

    cout << ans;

    return 0;
}