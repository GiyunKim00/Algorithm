#include <iostream>
#include <set>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t, k, a;
    string str;
    cin >> t;

    while (t--) {
        multiset<int> s;
        cin >> k;

        while (k--) {
            cin >> str >> a;
            if (str == "I") s.insert(a);
            else {
                if (s.empty()) continue;
                if (a == -1) s.erase(s.begin());
                else s.erase(prev(s.end()));
            }
        }

        if (s.empty()) cout << "EMPTY\n";
        else cout << *prev(s.end()) << " " << *s.begin() << "\n";
    }

    return 0;
}