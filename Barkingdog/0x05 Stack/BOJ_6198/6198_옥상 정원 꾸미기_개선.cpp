#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    long long cnt = 0;
    stack<int> s;
    cin >> N;

    for (int i = 0; i < N; ++i) {
        int k;
        cin >> k;

        while (!s.empty() && s.top() <= k) s.pop();

        cnt += s.size();

        s.push(k);
    }

    cout << cnt;

    return 0;
}