#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int n, m, k;
vector<int> arr[1001];
// set<int> arr[1001];
bool visit[1001];

void bfs() {
    queue<int> q;
    q.push(k);
    visit[k] = true;

    while (!q.empty()) {
        const int t = q.front();
        cout << t << " ";
        q.pop();

        for (const auto i: arr[t]) {
            if (visit[i]) continue;
            visit[i] = true;
            q.push(i);
        }
    }
}

void dfs(const int idx) {
    visit[idx] = true;
    cout << idx << " ";
    for (const auto i: arr[idx]) {
        if (visit[i]) continue;
        dfs(i);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int a, b;
    cin >> n >> m >> k;

    for (int i = 0; i < m; ++i) {
        cin >> a >> b;
        arr[a].push_back(b);
        arr[b].push_back(a);
        // arr[a].insert(b);
        // arr[b].insert(a);
    }
    for (int i = 1; i <= n; ++i) sort(arr[i].begin(), arr[i].end());

    dfs(k);
    cout << "\n";
    fill_n(visit, n + 1, false);
    bfs();

    return 0;
}