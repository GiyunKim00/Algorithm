#include <iostream>
#include <stack>

using namespace std;

int main() {
    while (1) {
        stack<char> stack;
        bool check = true;
        string str;
        getline(cin, str);
        if (str[0] == '.')
            break;

        for (int i = 0; str[i] != '.'; ++i) {
            if (str[i] == '(' || str[i] == '[')
                stack.push(str[i]);
            else if (str[i] == ')') {
                if (!stack.empty() && stack.top() == '(')
                    stack.pop();
                else {
                    check = false;
                    break;
                }
            } else if (str[i] == ']') {
                if (!stack.empty() && stack.top() == '[')
                    stack.pop();
                else {
                    check = false;
                    break;
                }
            }
        }
        if (check && stack.empty())
            cout << "yes\n";
        else
            cout << "no\n";
    }
    return 0;
}
