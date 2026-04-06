#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int cnt = 0;

char arr[5][5];
vector<int> ans;

bool bfs() {
    int tmp = 1;
    queue<pair<int, int> > q;
    int go[5][5] = {0,};
    bool visit[5][5] = {0,};

    for (const auto i: ans) {
        const int pos_x = i / 5;
        const int pos_y = i % 5;
        go[pos_x][pos_y] = true;
    }

    const auto k = ans.front();
    q.emplace(k / 5, k % 5);
    visit[k / 5][k % 5] = true;

    while (!q.empty()) {
        const auto [fst, snd] = q.front();
        q.pop();

        for (int i = 0; i < 4; ++i) {
            const int nx = fst + dx[i];
            const int ny = snd + dy[i];

            if (nx < 0 || ny < 0 || nx >= 5 || ny >= 5) continue;
            if (visit[nx][ny] || !go[nx][ny]) continue;

            tmp++;
            visit[nx][ny] = true;
            q.emplace(nx, ny);
        }
    }
    if (tmp == 7) return true;
    return false;
}

void recursive(const int idx, const int size) {
    if (size == 7) {
        int num = 0;
        for (const auto i: ans) {
            const int x = i / 5;
            const int y = i % 5;

            if (arr[x][y] == 'S') num++;
        }

        if (num >= 4) {
            if (bfs()) cnt++;
        }

        return;
    }

    if (idx == 25) return;

    ans.push_back(idx);
    recursive(idx + 1, size + 1);
    ans.pop_back();
    recursive(idx + 1, size);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    for (int i = 0; i < 5; ++i) {
        string s;
        cin >> s;
        for (int j = 0; j < 5; ++j) arr[i][j] = s[j];
    }

    recursive(0, 0);

    cout << cnt;
    return 0;
}
