#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;

    for (int i = 1; i <= n; ++i) {
        string s = to_string(i), a = "";
        for (const auto k: s) if (k == '3' || k == '6' || k == '9') a += '-';

        if (a.empty()) cout << i << " ";
        else cout << a << " ";
    }
    return 0;
}