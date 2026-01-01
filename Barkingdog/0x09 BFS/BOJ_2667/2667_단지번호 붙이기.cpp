#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int arr[26][26];
bool visit[26][26];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int N;
queue<pair<int, int>> q;

int bfs(int x, int y) {
    int cnt = 0;
    q.emplace(x, y);
    visit[x][y] = true;

    while (!q.empty()) {
        cnt++;
        auto t = q.front();
        q.pop();

        for (int i = 0; i < 4; ++i) {
            int nx = t.first + dx[i];
            int ny = t.second + dy[i];

            if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
            if (visit[nx][ny] || !arr[nx][ny]) continue;

            visit[nx][ny] = true;
            q.emplace(nx, ny);
        }
    }
    return cnt;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    vector<int> v;

    cin >> N;

    for (int i = 0; i < N; ++i) {
        string s;
        cin >> s;
        for (int j = 0; j < N; ++j) {

            arr[i][j] = s[j] - '0';
        }
    }

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (arr[i][j] == 1 && !visit[i][j]) v.push_back(bfs(i, j));
        }
    }

    sort(v.begin(), v.end());
    cout << v.size() << "\n";
    for (auto i: v) cout << i << "\n";

    return 0;
}