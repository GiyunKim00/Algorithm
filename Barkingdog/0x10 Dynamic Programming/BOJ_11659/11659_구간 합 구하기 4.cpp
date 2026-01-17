#include <iostream>

using namespace std;

int visit[100001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m, a, b, t, sum = 0;
    cin >> n >> m;

    for (int i = 1; i <= n; ++i) {
        cin >> t;
        sum += t;
        visit[i] = sum;
    }

    while (m--) {
        cin >> a >> b;
        cout << visit[b] - visit[a - 1] << "\n";
    }
    return 0;
}