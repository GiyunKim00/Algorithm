#include <iostream>
#include <queue>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    queue<int> q;
    int N;
    cin >> N;

    while (N--) {
        string s;
        cin >> s;
        if (s == "push") {
            int t;
            cin >> t;
            q.push(t);
        } else if (s == "pop") {
            if (!q.empty()) {
                cout << q.front() << "\n";
                q.pop();
            } else cout << "-1\n";
        } else if (s == "size") cout << q.size() << "\n";
        else if (s == "empty") {
            if (q.empty()) cout << "1\n";
            else cout << "0\n";
        } else if (s == "front") {
            if (!q.empty()) cout << q.front() << "\n";
            else cout << "-1\n";
        } else if (s == "back") {
            if (!q.empty()) cout << q.back() << "\n";
            else cout << "-1\n";
        }
    }

    return 0;
}