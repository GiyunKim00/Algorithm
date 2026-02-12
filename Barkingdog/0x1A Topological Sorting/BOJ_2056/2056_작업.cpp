#include <iostream>
#include <queue>

using namespace std;

int n;

vector<int> arr[10001];
int indegree[10001], duration[10001], dp[10001];

void bfs() {
    int ans = 0;
    queue<int> q;
    for (int i = 1; i <= n; ++i) {
        if (indegree[i]) continue;
        q.push(i);
        dp[i] = duration[i];
    }

    while (!q.empty()) {
        const auto t = q.front();
        q.pop();

        for (const int i: arr[t]) {
            dp[i] = max(dp[i], dp[t] + duration[i]);
            if (!--indegree[i]) q.push(i);
        }
    }
    for (int i = 1; i <= n; ++i) ans = (dp[i] > ans) ? dp[i] : ans;
    cout << ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    for (int i = 1; i <= n; ++i) {
        int time, num;
        cin >> time >> num;
        duration[i] = time;
        while (num--) {
            int a;
            cin >> a;
            arr[a].push_back(i);
            indegree[i]++;
        }
    }

    bfs();

    return 0;
}