#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

char arr[5][5];

int cnt;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
vector<int> ans;

bool bfs() {
    int num = 1;
    queue<pair<int, int>> q;
    bool selected[5][5] = {};
    for (int i: ans)
        selected[i / 5][i % 5] = true;
    bool visit[5][5] = {false,};
    int k = ans.front();
    int x = k / 5, y = k % 5;
    q.emplace(x, y);
    visit[x][y] = true;

    while (!q.empty()) {
        auto t = q.front();
        q.pop();

        for (int i = 0; i < 4; ++i) {
            int nx = t.first + dx[i];
            int ny = t.second + dy[i];

            if (nx < 0 || ny < 0 || nx >= 5 || ny >= 5) continue;
//            if (visit[nx][ny] || find(ans.begin(), ans.end(), nx * 5 + ny) == ans.end()) continue;
            if (visit[nx][ny] || !selected[nx][ny]) continue;
            visit[nx][ny] = true;
            q.emplace(nx, ny);
            num++;
        }
    }

    if (num == 7) return true;
    else return false;
}

void recursive(int idx, int n) {
    if (n == 7) {
        int num = 0;
        for (auto i: ans) {
            int x = i / 5;
            int y = i % 5;
            if (arr[x][y] == 'S') num++;
        }

        if (num >= 4) {
            if (bfs()) cnt++;
        }

        return;
    }
    if (idx == 25) return;

    ans.push_back(idx);
    recursive(idx + 1, n + 1);
    ans.pop_back();
    recursive(idx + 1, n);

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string s;
    for (int i = 0; i < 5; ++i) {
        cin >> s;
        for (int j = 0; j < 5; ++j) arr[i][j] = s[j];
    }

    recursive(0, 0);
    cout << cnt;
    return 0;
}