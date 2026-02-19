#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int cnt = 0;
    string s, tar;
    getline(cin, s);
    getline(cin, tar);

    int pos = 0;
    while (pos < s.size()){
        pos = static_cast<int>(s.find(tar, pos));
        if (pos == -1) break;
        else pos += static_cast<int>(tar.size());
        cnt++;
    }

    cout << cnt;

    return 0;
}