#include <iostream>
#include <stack>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N, ans;
    cin >> N;

    ans = N;

    for (int i = 0; i < N; ++i) {
        string str;
        stack<char> s;

        cin >> str;

        for (auto c: str) {
            if (s.empty()) s.push(c);
            else {
                if(s.top() == c) s.pop();
                else s.push(c);
            }
        }
        if (!s.empty()) ans--;
    }
    cout << ans;

    return 0;
}