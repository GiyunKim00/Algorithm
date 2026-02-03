#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;
    unordered_map<string, int> m;
    vector<string> v(n+1);

    for (int i = 1; i <= n; ++i) {
        string str;
        cin >> str;
        m.emplace(str, i);
        v[i] = str;
    }

    for (int i = 0; i < k; ++i) {
        string str;
        cin >> str;
        if (isalpha(str[0])) cout << m[str] << "\n";
        else cout << v[stoi(str)] << "\n";
    }

    return 0;
}