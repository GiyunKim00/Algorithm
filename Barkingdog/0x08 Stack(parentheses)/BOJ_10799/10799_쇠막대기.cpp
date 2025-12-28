#include <iostream>
#include <stack>

using namespace std;

int main() {
    string str;
    stack<char> s;
    char last_word;
    int ans = 0, cnt = 0;

    cin >> str;
    for (auto c: str) {
        if (s.empty()) s.push(c);
        else {
            if (c == ')') {
                if (last_word == ')') cnt--;
                else ans += cnt;
                s.pop();
            } else {
                s.push(c);
                if (last_word == '(') {
                    ans++;
                    cnt++;
                }
            }
        }
        last_word = c;
    }

    cout << ans;

    return 0;
}