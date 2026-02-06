#include <iostream>
#include <queue>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int k, a;
        long long int ans = 0;
        cin >> k;
        priority_queue<long long int, vector<long long int>, greater<> > q;
        while (k--) {
            cin >> a;
            q.push(a);
        }

        while (static_cast<int>(q.size()) != 1) {
            long long int cnt = q.top();
            q.pop();
            cnt += q.top();
            q.pop();
            q.push(cnt);
            ans += cnt;
        }

        cout << ans << "\n";
    }

    return 0;
}