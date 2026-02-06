#include <iostream>
#include <queue>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, a;
    priority_queue<int> max_q;
    priority_queue<int, vector<int>, greater<> > min_q;

    cin >> n;

    for (int i = 1; i <= n; ++i) {
        cin >> a;

        if (static_cast<int>(max_q.size()) > static_cast<int>(min_q.size())) min_q.push(a);
        else max_q.push(a);
        if (!min_q.empty() && max_q.top() > min_q.top()) {
            a = max_q.top();
            max_q.pop();
            max_q.push(min_q.top());
            min_q.pop();
            min_q.push(a);
        }

        cout << max_q.top() << "\n";
    }

    return 0;
}