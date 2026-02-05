#include <iostream>
#include <queue>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, a;
    cin >> n;
    priority_queue<int, vector<int>, greater<>> q;

    for (int i = 0; i < n*n; ++i){
        cin >> a;
        q.push(a);
        if ((int)q.size() > n) q.pop();
    }
    cout << q.top();
}