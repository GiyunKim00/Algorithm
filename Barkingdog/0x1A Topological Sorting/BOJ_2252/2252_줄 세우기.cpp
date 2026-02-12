#include <iostream>
#include <queue>

using namespace std;

int n, m;
vector<int> arr[32001], ans;
int indegree[32001];

void bfs() {
    queue<int> q;
    for (int i = 1; i <= n; ++i) {
        if (!indegree[i]) {
            ans.push_back(i);
            q.push(i);
        }
    }

    while (!q.empty()) {
        const int k = q.front();
        q.pop();
        for (const auto &t: arr[k]) {
            if (!--indegree[t]) {
                q.push(t);
                ans.push_back(t);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    ans.reserve(n+1);
    while (m--) {
        int a, b;
        cin >> a >> b;
        arr[a].push_back(b);
        indegree[b]++;
    }

    bfs();

    for (const auto &i: ans) cout << i << " ";

    return 0;
}