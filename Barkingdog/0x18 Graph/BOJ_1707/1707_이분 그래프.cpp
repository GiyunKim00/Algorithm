#include <iostream>
#include <queue>

using namespace std;

int n, m;

vector<vector<int>> arr;

void bfs(vector<int> &visit) {
    queue<int> q;
    for (int i = 1; i <= n; ++i) {
        if (visit[i]) continue;
        visit[i] = 1;
        q.push(i);

        while (!q.empty()) {
            const int k = q.front();
            q.pop();

            for (auto t: arr[k]) {
                if (visit[t] == 0) {
                    visit[t] = visit[k] % 2 + 1;
                    q.push(t);
                } else if (visit[t] == visit[k]) {
                    cout << "NO\n";
                    return;
                }
            }
        }
    }

    cout << "YES\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        arr.assign(n + 1, vector<int>());
        vector visit(n + 1, 0);

        for (int i = 0; i < m; ++i) {
            int a, b;
            cin >> a >> b;
            arr[a].push_back(b);
            arr[b].push_back(a);
        }

        bfs(visit);
    }

    return 0;
}