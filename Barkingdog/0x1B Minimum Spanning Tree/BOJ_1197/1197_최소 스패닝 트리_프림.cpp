#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

int v, e;
vector<pair<int, int>> arr[10001];
bool visit[10001];

void prim() {
    int cnt = 0, ans = 0;
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int> >, greater<>> q;
    visit[1] = true;
    for (auto [fst, snd]: arr[1]) q.emplace(snd, 1, fst);

    while (cnt < v - 1) {
        int cost, a, b;
        tie(cost, a, b) = q.top();
        q.pop();

        if (visit[b]) continue;
        visit[b] = true;
        cnt++;
        ans += cost;
        for (auto [fst, snd]: arr[b]) {
            if (visit[fst]) continue;
            q.emplace(snd, b, fst);
        }
    }

    cout << ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> v >> e;

    for (int i = 0; i < e; ++i) {
        int a, b, cost;
        cin >> a >> b >> cost;
        arr[a].emplace_back(b, cost);
        arr[b].emplace_back(a, cost);
    }

    prim();

    return 0;
}