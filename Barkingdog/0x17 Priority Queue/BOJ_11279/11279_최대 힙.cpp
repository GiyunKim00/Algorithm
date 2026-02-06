#include <iostream>
#include <queue>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, a;
    priority_queue<int> q;

    cin >> n;

    while (n--) {
        cin >> a;
        if (a) q.push(a);
        else {
            if (q.empty()) cout << "0\n";
            else {
                cout << q.top() << "\n";
                q.pop();
            }
        }
    }

    return 0;
}