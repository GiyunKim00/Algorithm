#include <iostream>
#include <stack>

using namespace std;

int main() {
    int N;
    stack<int> s;
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    cin.ignore();

    while (N--) {
        string command;
        cin >> command;

        if (command == "push") {
            int data;
            cin >> data;
            s.push(data);
        }

        if (command == "pop") {
            if (s.empty()) cout << "-1\n";
            else {
                cout << s.top() << "\n";
                s.pop();
            }
        }

        if (command == "size") cout << s.size() << "\n";

        if (command == "empty") {
            if (s.empty()) cout << "1\n";
            else cout << "0\n";
        }

        if (command == "top") {
            if (s.empty()) cout << "-1\n";
            else cout << s.top() << "\n";
        }
    }

    return 0;
}
