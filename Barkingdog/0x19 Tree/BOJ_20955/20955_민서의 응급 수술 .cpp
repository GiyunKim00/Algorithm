#include <iostream>
#include <queue>

using namespace std;

int n, m, tree = 0, cycle = 0;
vector<int> arr[100001];
bool visit[100001];

/**
 * [Tree 내 Cycle 세는 방법]
 * Cycle : Edge 개수 - (Node 개수 - 1)
 * 이 때, Edge는 무방향이므로, 입력 당시 양방향으로 push해주었기에 /2를 해주어야 함.
 */
void bfs() {
    queue<int> q;
    for (int i = 1; i <= n; ++i) {
        if (visit[i]) continue;

        int edge = 0, node = 0;
        tree++;
        visit[i] = i;
        q.push(i);

        while (!q.empty()) {
            const int k = q.front();
            node++;
            q.pop();
            for (auto t: arr[k]) {
                if (visit[t]) continue;
                visit[t] = true;
                q.push(t);
            }
            edge += static_cast<int>(arr[k].size());
        }
        edge /= 2;
        cycle += edge - (node - 1);
    }

    cout << cycle + tree - 1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    while (m--) {
        int a, b;
        cin >> a >> b;
        arr[a].push_back(b);
        arr[b].push_back(a);
    }

    bfs();

    return 0;
}