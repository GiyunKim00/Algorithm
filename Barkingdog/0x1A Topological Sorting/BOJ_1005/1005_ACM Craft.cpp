#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

int n, w, ans = 0;
int indegree[1001], duration[1001], dp[1001];

void bfs(const vector<vector<int>>& arr) {
    queue<int> q;
    for (int i = 1; i <= n; ++i) {
        if (indegree[i]) continue;
        q.push(i);
        dp[i] = duration[i];
    }

    while (!q.empty()) {
        const int t = q.front();
        q.pop();

        for (const int i: arr[t]) {
            dp[i] = max(dp[i], dp[t] + duration[i]);
            if (!--indegree[i]) q.push(i);
        }
    }
    cout << dp[w] << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int k;

        cin >> n >> k;
        vector<vector<int>> arr(n+1);

        for (int i = 1; i <= n; ++i) cin >> duration[i];

        while (k--) {
            int a, b;
            cin >> a >> b;
            arr[a].push_back(b);
            indegree[b]++;
        }

        cin >> w;

        bfs(arr);
        memset(indegree, 0, sizeof(indegree));
        memset(dp, 0, sizeof(dp));
        ans = 0;
    }

    return 0;
}