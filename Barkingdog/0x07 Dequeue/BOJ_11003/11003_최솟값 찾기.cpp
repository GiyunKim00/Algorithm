#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N, L;
    vector<int> q, ans;
    cin >> N >> L;

    for (int i = 0; i < N; ++i) {
        int t;
        cin >> t;
        q.push_back(t);
    }

    for (int i = 0; i < N; ++i) {
        int k = i - L + 1;
        int min = 1000000001;
        if (k >= 0) {
            for (int j = k; j <= i; ++j) if (q[j] < min) min = q[j];
        } else for (int j = 0; j <= i; ++j) if (q[j] < min) min = q[j];
        ans.push_back(min);
    }

    for(auto i : ans) cout << i << " ";

    return 0;
}