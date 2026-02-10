#include <iostream>
#include <queue>

using namespace std;
int n, r, q;
vector<int> tree[100001];
int p[100001], ans[100001];

void bfs(const int root, const int mode) {
    int cnt = 1;
    queue<int> que;
    que.push(root);
    if(!mode) p[root] = root;

    while (!que.empty()){
        const int i = que.front();
        que.pop();
        for (const auto k : tree[i]){
            if (k == p[i]) continue;
            cnt++;
            p[k] = i;
            que.push(k);
        }
    }
    if (mode) cout << cnt << "\n";
}

int dfs(const int root) {
    int cnt = 1;
    for (auto i : tree[root]){
        if (i == p[root]) continue;
        p[i] = root;
        cnt += dfs(i);
    }
    ans[root] = cnt;
    return cnt;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> r >> q;

    for (int i = 0; i < n - 1; ++i){
        int a, b;
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }

    dfs(r);

    while (q--){
        int a;
        cin >> a;
        cout << ans[a] << "\n";
        // bfs(a, 1);
    }

    return 0;
}