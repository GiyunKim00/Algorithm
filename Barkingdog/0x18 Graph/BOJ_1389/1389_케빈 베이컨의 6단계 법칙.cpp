#include <iostream>
#include <queue>

using namespace std;

vector<int> arr[101];

void bfs(const int idx, vector<int> &visit) {
    queue<int> q;
    q.emplace(idx);
    visit[idx] = 0;

    while (!q.empty()) {
        const int k = q.front();
        q.pop();

        for (auto i: arr[k]) {
            if (visit[i] == -1) {
                visit[i] = visit[k] + 1;
                q.emplace(i);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, min_val = 1000000;
    cin >> n >> m;
    vector<int> ans(n+1);

    while (m--) {
        int a, b;
        cin >> a >> b;
        arr[a].push_back(b);
        arr[b].push_back(a);
    }

    for (int i = 1; i <= n; ++i) {
        int cnt = 0;
        vector visit(n + 1, -1);
        bfs(i, visit);
        for (int k = 1; k<=n; ++k) if (visit[k] != -1 && k != i) cnt += visit[k];
        min_val = min(min_val, cnt);
        ans[i] = cnt;
    }

    for (int i = 1; i <= n; ++i) {
        if (ans[i] == min_val) {
            cout << i;
            break;
        }
    }

    return 0;
}