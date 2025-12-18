#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;

    stack<int> s;
    vector<char> ans;
    int next = 1;

    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;

        while (next <= x) {
            s.push(next++);
            ans.push_back('+');
        }

        if (s.empty() || s.top() != x) {
            cout << "NO";
            return 0;
        }

        s.pop();
        ans.push_back('-');
    }

    for (char c : ans) cout << c << '\n';

    return 0;
}
