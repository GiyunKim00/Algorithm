#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int state = 0;

    int m;
    cin >> m;

    while (m--) {
        string s;
        int a;
        cin >> s;

        if (s == "add") {
            cin >> a;
            state |= 1 << (a - 1);
        } else if (s == "remove") {
            cin >> a;
            state &= ~(1 << (a - 1));
        } else if (s == "check") {
            cin >> a;
            cout << ((state >> (a - 1)) & 1) << "\n";
        } else if (s == "toggle") {
            cin >> a;
            state ^= 1 << (a - 1);
        } else if (s == "all") state = 0xfffff;
        else state = 0;
    }

    return 0;
}