#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m;
vector<int> arr[1001];
int visit[1001];

void bfs() {
    int cnt = 0;
    queue<int> q;
    for (int i = 1; i <= n; ++i) {
        if (visit[i]) continue;
        cnt++;
        visit[i] = true;
        q.push(i);

        while (!q.empty()) {
            const int k = q.front();
            q.pop();
            for (const auto idx: arr[k]) {
                if (visit[idx]) continue;
                q.push(idx);
                visit[idx] = true;
            }
        }
    }

    cout << cnt;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int a, b;
    cin >> n >> m;

    for (int i = 0; i < m; ++i) {
        cin >> a >> b;
        arr[a].push_back(b);
        arr[b].push_back(a);
    }

    bfs();

    return 0;
}