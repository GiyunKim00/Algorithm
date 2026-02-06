#include <iostream>
#include <queue>
#include <vector>

using namespace std;

vector<int> arr[101];
bool visit[101];
int ans1;
void bfs() {
    int ans = 0;
    queue<int> q;
    q.push(1);
    visit[1] = true;

    while (!q.empty()) {
        const int k = q.front();
        q.pop();

        for (const auto i: arr[k]) {
            if (visit[i]) continue;
            ans++;
            q.push(i);
            visit[i] = true;
        }
    }

    cout << ans;
}

void dfs(const int i) {
    visit[i] = true;
    for (const auto k : arr[i]) {
        if (visit[k]) continue;
        ans1++;
        dfs(k);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, a, b;

    cin >> n >> m;

    while (m--) {
        cin >> a >> b;
        arr[a].push_back(b);
        arr[b].push_back(a);
    }
    dfs(1);
    //bfs();
    cout << ans1;
    return 0;
}