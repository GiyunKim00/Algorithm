#include <iostream>
#include <deque>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N, L;
    deque<pair<int, int>> q;
    cin >> N >> L;
    int ans[N];

    for (int i = 0; i < N; ++i) {
        if (q.front().second < i - L + 1) q.pop_front();
        int t;
        cin >> t;
        while (!q.empty() && q.back().first > t) q.pop_back();
        q.emplace_back(t, i);

        cout << q.front().first << " ";
    }

    return 0;
}