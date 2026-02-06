#include <iostream>
#include <queue>

using namespace std;

int n, m;
vector<int> arr[501];
bool visit[501];

void bfs() {
    int ans = 0;
    queue<pair<int, int> > q;
    q.emplace(1, 0);
    visit[1] = true;

    while (!q.empty()) {
        auto [fst, snd] = q.front();
        q.pop();
        if (snd >= 2) continue;
        for (const auto i: arr[fst]) {
            if (visit[i]) continue;
            ans++;
            visit[i] = true;
            q.emplace(i, snd + 1);
        }
    }

    cout << ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int a, b;

    cin >> n >> m;

    while (m--) {
        cin >> a >> b;
        arr[a].push_back(b);
        arr[b].push_back(a);
    }

    bfs();

    return 0;
}