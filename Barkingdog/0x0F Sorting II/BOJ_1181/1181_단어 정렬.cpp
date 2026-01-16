#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(string a, string b) {
    if (a.size() == b.size()) {
        for (int i = 0; i < a.size(); ++i) {
            if (a[i] < b[i]) return true;
            if (a[i] > b[i]) return false;
        }
    }
    return a.size() < b.size();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    string s;
    cin >> n;

    vector<string> ans;
    while (n--) {
        cin >> s;
        ans.push_back(s);
    }

    sort(ans.begin(), ans.end(), compare);
    ans.erase(unique(ans.begin(), ans.end()), ans.end());

    for (auto i: ans) cout << i << "\n";

    return 0;
}