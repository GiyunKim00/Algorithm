#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int N, X;
bool visit[200001];
vector<int> v;

void bfs() {
    queue<pair<int, int>> q;
    q.emplace(N, 0);
    visit[N] = true;

    while (!q.empty()) {
        auto t = q.front();
        q.pop();
        if(t.first == X){
            v.push_back(t.second);
            continue;
        }

        for (int nx: {2 * t.first, t.first + 1, t.first - 1}) {
            if (nx < 0 || nx >= 2 * X) continue;
            if (visit[nx]) continue;
            if (nx == 2 * t.first) q.emplace(nx, t.second);
            else q.emplace(nx, t.second + 1);
            if(nx != X) visit[nx] = true;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> X;

    if(X < N) cout << N - X;
    else {
        bfs();
        sort(v.begin(), v.end());
        cout << v.front();
    }
    return 0;
}