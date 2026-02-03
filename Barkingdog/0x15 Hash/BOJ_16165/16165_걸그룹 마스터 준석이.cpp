#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, k;
    string a, b;
    cin >> n >> m;
    unordered_map<string, vector<string>> arr;
    unordered_map<string, string> name;

    while (n--) {
        cin >> a >> k;
        for (int i = 0; i<k; ++i) {
            cin >> b;
            arr[a].push_back(b);
            name[b] = a;
        }
        sort(arr[a].begin(), arr[a].end());
    }

    while (m--) {
        cin >> a >> k;
        if (k) cout << name[a] << "\n";
        else for (const auto& i : arr[a]) cout << i << "\n";
    }
    return 0;
}