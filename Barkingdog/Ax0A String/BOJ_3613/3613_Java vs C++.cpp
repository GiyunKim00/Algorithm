#include <iostream>

using namespace std;

int check(const string &str) {
    const int size = str.size();
    if (str[0] == '_' || isupper(str[0]) || str[str.size() - 1] == '_') return 3;
    bool upper_case = false, under_bar = false;
    for (int i = 1; i < size; ++i) {
        if (isupper(str[i])) {
            if (under_bar) return 3;
            upper_case = true;
        } else if (str[i] == '_') {
            if (str[i - 1] == '_' || upper_case) return 3;
            under_bar = true;
        }
    }
    if (upper_case && under_bar) return 3;
    if (upper_case) return 0;
    if (under_bar) return 1;
    return 2;
}

void java_to_c(const string &s) {
    string tmp = "";
    const int size = s.size();
    for (int i = 0; i < size; ++i) {
        if (isupper(s[i])) {
            tmp += '_';
            tmp +=  tolower(s[i]);
        }
        else tmp += s[i];
    }

    cout << tmp;
}

void c_to_java(const string &s) {
    string tmp = "";
    const int size = s.size();
    for (int i = 0; i < size; ++i) {
        if (s[i] == '_') {
            i++;
            tmp += toupper(s[i]);
        } else tmp += s[i];
    }

    cout << tmp;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;

    if (const int mode = check(s); mode == 0) java_to_c(s);
    else if (mode == 1) c_to_java(s);
    else if (mode == 2) cout << s;
    else cout << "Error!";

    return 0;
}