#include <algorithm>
#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

vector<string> split(const string &s) {
    vector<string> tmp;
    int size = s.size();
    int pos = 0;
    while (pos < size) {
        int nxt_pos = s.find(' ', pos);
        if (nxt_pos == -1) nxt_pos = size;
        if (nxt_pos - pos > 0) tmp.push_back(s.substr(pos, nxt_pos - pos));
        pos = nxt_pos + 1;
    }

    return tmp;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string s;
        unordered_set<string> voice;
        getline(cin, s);
        vector<string> str = split(s);

        while (true) {
            string tmp;
            getline(cin, tmp);
            vector<string> tmp_str = split(tmp);
            if (tmp_str[0] == "what") break;
            voice.insert(tmp_str[tmp_str.size() - 1]);
        }

        for (const auto &k: str)
            if (voice.find(k) == voice.end()) cout << k << " ";
    }

    return 0;
}