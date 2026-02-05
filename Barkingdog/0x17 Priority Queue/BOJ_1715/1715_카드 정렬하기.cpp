#include <iostream>
#include <queue>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    long long int cnt = 0, ans = 0;
    cin >> n;
    priority_queue<int, vector<int>, greater<>> q;

    while (n--){
        int a;
        cin >> a;
        q.push(a);
    }

    while (q.size() != 1){
        cnt = q.top();
        q.pop();
        cnt += q.top();
        q.pop();
        ans += cnt;
        q.push(cnt);
    }

    cout << ans;

    return 0;
}
