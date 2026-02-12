#include <iostream>
#include <queue>

using namespace std;

int indegree[32001];


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<int> arr[n + 1], ans;

    while (m--) {
        int a, b;
        cin >> a >> b;
        arr[a].push_back(b);
        indegree[b]++;
    }

    priority_queue<int, vector<int>, greater<> > q;
    for (int i = 1; i <= n; ++i) if (!indegree[i]) q.push(i);

    while (!q.empty()) {
        const int t = q.top();
        q.pop();
        ans.push_back(t);
        for (const int &i: arr[t]) {
            if (!--indegree[i]) q.push(i);
        }
    }

    for (const int &i: ans) cout << i << " ";

    return 0;
}