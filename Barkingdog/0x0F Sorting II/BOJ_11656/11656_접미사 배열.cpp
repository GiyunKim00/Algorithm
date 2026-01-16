#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    string s;
    cin >> s;
    vector<string> ans;
    for (int i = 0; i < s.size(); ++i) ans.push_back(s.substr(i));
    sort(ans.begin(), ans.end());

    for (auto i: ans) cout << i << "\n";
    return 0;
}