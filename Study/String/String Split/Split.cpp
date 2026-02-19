#include <iostream>
#include <vector>

using namespace std;

vector<string> split(const string &s, const string &sep) {
    vector<string> str;
    int pos = 0;
    while (pos < s.size()){
        int nxt_pos = s.find(sep, pos);
        if (nxt_pos == -1) nxt_pos = s.size();
        if (nxt_pos - pos > 0) str.push_back(s.substr(pos, nxt_pos - pos));
        pos = nxt_pos + sep.size();
    }

    return str;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s = "Hi My Name Is Kim Giyun.";
    string sep = " ";

    vector<string> chunk = split(s, sep);
    for (const auto &i : chunk) cout << i << "\n";

    return 0;
}