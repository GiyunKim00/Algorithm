#include <iostream>
#include <queue>

using namespace std;

int n, indegree[101], quantity[101][101], dp[101];
bool ans[101];
vector<int> arr[101];

void bfs() {
    queue<int> q;
    for (int i = 1; i <= n; ++i) {
        if (indegree[i]) continue;
        q.push(i);
        dp[i] = 1;
    }

    while (!q.empty()) {
        const int t = q.front();
        q.pop();

        for (const int i: arr[t]) {
            dp[i] += quantity[t][i] * dp[t];
            if (!--indegree[i]) q.push(i);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int m;

    cin >> n >> m;

    while (m--) {
        int a, b, c;
        cin >> a >> b >> c;
        arr[a].push_back(b);
        indegree[b]++;
        quantity[a][b] = c;
        ans[a] = true;
    }

    bfs();

    for (int i = 1; i <= n; ++i) if (!ans[i]) cout << i << " " << dp[i] << "\n";

    return 0;
}