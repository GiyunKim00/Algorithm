#include <iostream>
#include <queue>

using namespace std;
int F, S, G, U, D;

int arr[1000001];
int visit[1000001];

int bfs() {
    queue<int> q;
    q.push(S);
    visit[S] = 1;

    while (!q.empty()) {

        auto t = q.front();
        q.pop();
        for (int i: {U, -D}) {
            int nx = t + i;

            if (nx <= 0 || nx > F) continue;
            if (arr[nx] == 1) return visit[t];

            if (visit[nx]) continue;

            visit[nx] = visit[t] + 1;
            q.push(nx);
        }
    }

    return 0;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> F >> S >> G >> U >> D;

    if (G == S) cout << 0;
    else {
        arr[G] = 1;
        int cnt = bfs();
        if (cnt) cout << cnt;
        else cout << "use the stairs";
    }

    return 0;
}