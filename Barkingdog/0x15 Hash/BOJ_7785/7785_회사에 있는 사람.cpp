#include <iostream>
#include <vector>
#include <set>

using namespace std;

/**
 * set 자료구조에서 compare를 활용할 경우 구조체 형식으로 작성해야 함.
 */
struct compare {
    bool operator() (const string &a, const string &b) const{
        return a > b;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    set<string, compare> s;

    for (int i = 0; i<n; ++i) {
        string a, b;
        cin >> a >> b;
        if (b == "enter") s.insert(a);
        else s.erase(a);
    }

    for (auto i: s) cout << i << "\n";

    return 0;
}