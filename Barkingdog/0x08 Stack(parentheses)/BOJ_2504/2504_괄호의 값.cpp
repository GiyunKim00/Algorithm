#include <iostream>
#include <stack>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string str;
    bool error = false;
    int ans = 0, cnt = 0, mul;
    stack<char> s;
    int arr[31] = {0,};
    cin >> str;

    for (auto c: str) {
        if (s.empty()) {
            if (c == ')' || c == ']') {
                error = true;
                break;
            } else {
                s.push(c);
                cnt++;
            }
        } else {
            if ((s.top() == '(' && c == ']') || (s.top() == '[' && c == ')')) {
                error = true;
                break;
            }

            if (c == ')' || c == ']') {
                if (c == ')') mul = 2;
                else mul = 3;
                cnt--;
                if (cnt == 0) {
                    if (arr[1] != 0) {
                        ans += arr[1] * mul;
                        arr[1] = 0;
                    } else ans += mul;
                } else {
                    if (arr[cnt + 1] != 0) {
                        arr[cnt] += arr[cnt + 1] * mul;
                        arr[cnt + 1] = 0;
                    } else arr[cnt] += mul;
                }
                s.pop();
            } else {
                cnt++;
                s.push(c);
            }

        }
    }

    if (!s.empty() || error) cout << "0";
    else cout << ans;

    return 0;
}