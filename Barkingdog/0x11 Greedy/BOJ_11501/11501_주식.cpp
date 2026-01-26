#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(pair<int, int>& a, pair<int, int>& b) {
    if (a.first == b.first) return a.second < b.second;
    return a.first > b.first;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, t;
    cin >> n;

    while (n--){
        long long int sum = 0;
        int idx = 0;
        vector<pair<int, int>> max_val;
        cin >> t;
        vector<int> arr(t);

        for (int i = 0; i < t; ++i){
            cin >> arr[i];
            max_val.emplace_back(arr[i], i);
        }

        sort(max_val.begin(), max_val.end(), compare);

        for (auto i : max_val) while (idx <= i.second) sum += i.first - arr[idx++];

        cout << sum << "\n";
    }
}
