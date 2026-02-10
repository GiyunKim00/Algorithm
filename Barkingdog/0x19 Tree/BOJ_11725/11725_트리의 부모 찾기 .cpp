#include <iostream>
#include <queue>
using namespace std;

vector<int> tree[100001];
int p[100001];

void bfs() {
    queue<int> q;
    q.push(1);

    while (!q.empty()){
        const int now = q.front();
        q.pop();

        for (auto i : tree[now]){
            if (p[now] == i) continue;
            q.push(i);
            p[i] = now;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;

    cin >> n;
    for (int i = 0; i < n - 1; ++i){
        int a, b;
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }

    bfs();

    for (int i = 2; i <= n; ++i) cout << p[i] << "\n";

    return 0;
}