#include <iostream>
#include <queue>

using namespace std;

vector<int> truth, member[51];
vector<bool> visit(51);

void bfs() {
    queue<int> q;
    for (const auto i: truth) {
        if (!visit[i]) {
            visit[i] = true;
            q.push(i);
        }
    }

    while (!q.empty()) {
        const int t = q.front();
        q.pop();

        for (const auto k: member[t]) {
            if (!visit[k]) {
                visit[k] = true;
                q.push(k);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, t, ans = 0;
    cin >> n >> m >> t;
    vector<int> party[m];
    if (t) {
        truth.reserve(t);
        while (t--) {
            int a;
            cin >> a;
            truth.push_back(a);
        }
    }

    for (int idx = 0; idx < m; ++idx) {
        int a, b;
        cin >> a;
        for (int i = 0; i < a; ++i) {
            cin >> b;
            party[idx].push_back(b);
        }

        for (int i = 1; i < a; ++i) {
            member[party[idx][i]].push_back(party[idx][i - 1]);
            member[party[idx][i - 1]].push_back(party[idx][i]);
        }
    }

    bfs();

    for (int idx = 0; idx < m; ++idx) {
        bool known = false;
        for (const auto i: party[idx]) {
            if (visit[i]) {
                known = true;
                break;
            }
        }
        if (!known) ans++;
    }

    cout << ans;

    return 0;
}