#include <iostream>
#include <set>
#include <map>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    multiset<int> bag;
    multimap<int, int, greater<>> gem;
    int n, k;
    long long int ans = 0;

    cin >> n >> k;

    while (n--){
        int weight, value;
        cin >> weight >> value;
        gem.emplace(value, weight);
    }

    for (int i = 0; i < k; ++i){
        int area;
        cin >> area;
        bag.insert(area);
    }

    for (auto it = gem.begin(); it != gem.end(); ++it){
        auto i = bag.lower_bound(it->second);
        if (i == bag.end()) continue;
        ans += it->first;
        bag.erase(i);
    }

    cout << ans;

    return 0;
}