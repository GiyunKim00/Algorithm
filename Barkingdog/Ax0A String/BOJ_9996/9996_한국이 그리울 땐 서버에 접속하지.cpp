#include <iostream>
#include <vector>

using namespace std;

pair<string, string> split(const string &str) {
    const string sep = "*";
    vector<string> tmp;
    int pos = 0;
    const int str_size = str.size(), sep_size = 1;
    while (pos < str_size) {
        int nxt_pos = str.find(sep, pos);
        if (nxt_pos == -1) nxt_pos = str_size;
        if (nxt_pos - pos > 0) tmp.push_back(str.substr(pos, nxt_pos - pos));
        pos = nxt_pos + sep_size;
    }

    return {tmp[0], tmp[1]};
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, sep1_size, sep2_size;
    string pattern;

    cin >> n >> pattern;

    const auto [sep1, sep2] = split(pattern);
    sep1_size = sep1.size(), sep2_size = sep2.size();
    while (n--) {
        bool check = true;
        string s;
        cin >> s;
        if (sep1_size + sep2_size > s.size()) {
            cout << "NE\n";
            continue;
        }
        for (int i = 0; i < sep1_size; ++i) {
            if (s[i] != sep1[i]) {
                check = false;
                cout << "NE\n";
                break;
            }
        }

        if (!check) continue;
        int idx = 0;
        for (int i = s.size() - sep2_size; i < s.size(); ++i) {
            if (s[i] != sep2[idx++]) {
                check = false;
                cout << "NE\n";
                break;
            }
        }

        if (check) cout << "DA\n";
    }

    return 0;
}