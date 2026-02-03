#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, k;
    string a, b;
    cin >> n >> m;
    map<string, string> name;

    while (n--) {
        cin >> a >> k;
        for (int i = 0; i<k; ++i) {
            cin >> b;
            name[b] = a;
        }
    }

    while (m--) {
        cin >> a >> k;
        if (k) cout << name[a] << "\n";
        else for (const auto&[fst, snd] : name) if (snd == a) cout << fst << "\n";
    }
    return 0;
}