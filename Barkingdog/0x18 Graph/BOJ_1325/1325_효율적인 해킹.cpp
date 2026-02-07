#include <iostream>
#include <queue>

using namespace std;

int bfs(const int idx, bool *visit, const vector<int> *arr) {
    int cnt = 0;
    queue<int> q;
    visit[idx] = true;
    q.push(idx);

    while (!q.empty()) {
        const int k = q.front();
        q.pop();
        cnt++;

        for (const auto i: arr[k]) {
            if (visit[i]) continue;
            q.push(i);
            visit[i] = true;
        }
    }

    return cnt;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, max_val = 0;
    cin >> n >> m;

    vector<int> arr[n + 1], ans(n + 1);
    bool visit[n + 1];
    while (m--) {
        int a, b;
        cin >> a >> b;
        arr[b].push_back(a);
    }

    for (int i = 1; i <= n; ++i) {
        fill(visit, visit + n + 1, false);
        ans[i] = bfs(i, visit, arr);
        max_val = max(ans[i], max_val);
    }

    for (int i = 1; i <= n; ++i) if (ans[i] == max_val) cout << i << " ";

    return 0;
}