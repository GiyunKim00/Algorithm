#include <iostream>
#include <unordered_set>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    unordered_set<string> arr;
    cin >> s;

    for (int i = 0; i < s.size(); ++i) for (int j = 1; j <= s.size() - i; ++j) arr.insert(s.substr(i, j));

    cout << arr.size();

    return 0;
}
