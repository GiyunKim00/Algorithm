#include <iostream>
#include <queue>

using namespace std;
/*
vector<int> arr[100001];
int compliment[100001], ans[100001];;

void dfs(const int node, const int value) {
    ans[node] = value;
    for (const auto i: arr[node]) dfs(i, value + compliment[i]);
}
*/

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<int> arr[n + 1], ans(n + 1, 0), compliment(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        int a;
        cin >> a;
        if (a != -1) arr[a].push_back(i);
    }

    while (m--) {
        int a, b;
        cin >> a >> b;
        compliment[a] += b;
    }

    queue<int> q;
    q.push(1);
    while (!q.empty()) {
        const int t = q.front();
        q.pop();
        for (const auto i: arr[t]) {
            ans[i] = ans[t] + compliment[i];
            q.push(i);
        }
    }

    for (int i = 1; i <= n; ++i) cout << ans[i] << " ";

    return 0;
}