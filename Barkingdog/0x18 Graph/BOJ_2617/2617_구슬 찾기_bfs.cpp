#include <iostream>
#include <queue>

using namespace std;
int n, m, limit;

bool dfs(const vector<int> *arr, const int idx) {
    int cnt = 0;
    vector<int> visit(n + 1, -1);
    queue<int> q;

    q.push(idx);
    visit[idx] = 0;

    while (!q.empty()) {
        const int t = q.front();
        q.pop();
        if (visit[t] >= limit || cnt >= limit) return true;
        for (const auto i: arr[t]) {
            if (visit[i] == -1) {
                visit[i] = visit[t] + 1;
                q.push(i);
                cnt++;
            }
        }
    }

    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int cnt = 0;
    cin >> n >> m;
    limit = (n + 1) / 2;
    vector<int> arr_asc[n + 1], arr_des[n + 1];

    while (m--) {
        int a, b;
        cin >> a >> b;
        arr_asc[b].push_back(a);
        arr_des[a].push_back(b);
    }

    for (int i = 1; i <= n; ++i) if (dfs(arr_asc, i) || dfs(arr_des, i)) cnt++;

    cout << cnt;
    return 0;
}