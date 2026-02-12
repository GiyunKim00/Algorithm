#include <iostream>
#include <queue>

using namespace std;

int n, indegree[1001];
vector<int> arr[1001], ans;

void bfs() {
    queue<int> q;
    for (int i = 1; i <= n; ++i) {
        if (indegree[i]) continue;
        q.push(i);
        ans.push_back(i);
    }

    while (!q.empty()) {
        const auto k = q.front();
        q.pop();

        for (const auto &i: arr[k]) {
            if (!--indegree[i]) {
                q.push(i);
                ans.push_back(i);
            }
        }
    }

    if (ans.size() != n) cout << 0;
    else for (const auto &i: ans) cout << i << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int m;

    cin >> n >> m;
    ans.reserve(n);

    while (m--) {
        int k;
        cin >> k;
        vector<int> tmp(k);
        for (int i = 0; i < k; ++i) cin >> tmp[i];
        for (int i = 1; i < k; ++i) {
            arr[tmp[i - 1]].push_back(tmp[i]);
            indegree[tmp[i]]++;
        }
    }

    bfs();

    return 0;
}