#include <iostream>
#include <vector>

using namespace std;

vector<int> failure(const string& s) {
    vector<int> f(s.size());
    int j = 0;
    for (int i = 1; i < s.size(); ++i){
        while (j > 0 && s[i] != s[j]) j = f[j - 1];
        if (s[i] == s[j]) f[i] = ++j;
    }

    return f;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string a, b, s = "";
    cin >> a >> b;

    for (const char& i : a) if (!isdigit(i)) s += i;

    vector<int> f = failure(b);
    int j = 0;
    for (int i = 0; i < s.size(); ++i){
        while (j > 0 && s[i] != b[j]) j = f[j - 1];
        if (s[i] == b[j]) j++;
        if (j == b.size()){
            cout << 1;
            return 0;
        }
    }

    cout << 0;

    return 0;
}