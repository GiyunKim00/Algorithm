#include <iostream>
#include <queue>

using namespace std;

int n;
vector<int> arr[101];
bool visit[101][101];

void bfs(const int x, const int y) {
    queue<int> q;
    q.push(y);
    visit[x][y] = true;

    while (!q.empty()) {
        const int k = q.front();
        q.pop();

        for (const auto i: arr[k]) {
            if (visit[x][i]) continue;
            visit[x][i] = true;
            q.emplace(i);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int a;

    cin >> n;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> a;
            if (a) arr[i].push_back(j);
        }
    }

    for (int i = 1; i <= n; ++i) {
        for (const auto k: arr[i])
            if (!visit[i][k]) bfs(i, k);
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) cout << visit[i][j] << " ";
        cout << "\n";
    }

    return 0;
}