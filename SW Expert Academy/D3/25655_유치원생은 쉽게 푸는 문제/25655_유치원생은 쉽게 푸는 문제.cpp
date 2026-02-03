#include <iostream>

using namespace std;

int main() {
    int test_case, T;
    cin >> T;

    for (test_case = 1; test_case <= T; ++test_case) {
        int k;
        string s = "";
        cin >> k;
        if (k == 1) cout << "0\n";
        else {
            if (k % 2) s += '4';
            for (int i = 0; i < k / 2; ++i) s += '8';
            cout << s << "\n";
        }
    }
    return 0;
}
