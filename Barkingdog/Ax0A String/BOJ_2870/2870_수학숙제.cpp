#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(const string &a, const string &b) {
    if (a.length() == b.length()) {
        for (int i = 0; i< a.length(); ++i) {
            if (a[i] == b[i]) continue;
            if (a[i] < b[i]) return true;
            return false;
        }
    }
    return a.length() < b.length();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    vector<string> ans;

    cin >> t;

    while (t--) {
        string s, tmp = "";
        cin >> s;
        for (const auto &c: s) {
            if (isdigit(c)) tmp += c;
            else if (!tmp.empty()) {
                int i = 0;
                while (i < tmp.size() && tmp[i] == '0') i++;
                if (i == tmp.size()) tmp = "0";
                else tmp = tmp.substr(i);
                ans.push_back(tmp);
                tmp = "";
            }
        }

        if (!tmp.empty()) {
            int i = 0;
            while (i < tmp.size() && tmp[i] == '0') i++;
            if (i == tmp.size()) tmp = "0";
            else tmp = tmp.substr(i);
            ans.push_back(tmp);
        }
    }

    sort(ans.begin(), ans.end(), compare);
    for (const auto &i: ans) cout << i << "\n";

    return 0;
}