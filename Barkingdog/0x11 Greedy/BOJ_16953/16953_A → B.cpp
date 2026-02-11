#include <iostream>
#include <queue>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;

    cin >> n >> m;

    queue<pair<int, int>> q;
    q.emplace(n, 1);

    while (!q.empty()) {
        const auto [fst, snd] = q.front();
        q.pop();
        if (fst == m) {
            cout << snd;
            return 0;
        }
        for (const auto i: {fst * 2, fst * 10 + 1}) {
            if (i > m) continue;
            q.emplace(i, snd + 1);
        }
    }

    cout << "-1";

    return 0;
}