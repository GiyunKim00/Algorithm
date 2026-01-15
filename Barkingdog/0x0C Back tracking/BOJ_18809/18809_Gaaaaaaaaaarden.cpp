#include <iostream>
#include <queue>
#include <tuple>

using namespace std;
 
int N, M, G, R, sum;
int arr[50][50];
bool check[50][50];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
vector<pair<int, int>> v;
vector<tuple<int, int, int>> ans;

void bfs() {
    int flower = 0;
    queue<tuple<int, int, int, int>> q;
    pair<int, int> visit[50][50];

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            visit[i][j] = {0, -1};

    for (auto i: ans) {
        q.emplace(get<0>(i), get<1>(i), get<2>(i), 1);
        visit[get<0>(i)][get<1>(i)] = {1, get<2>(i)};
    }

    while (!q.empty()) {
        auto t = q.front();
        q.pop();
        if (visit[get<0>(t)][get<1>(t)].second == -2) continue;
        for (int i = 0; i < 4; ++i) {
            int nx = get<0>(t) + dx[i];
            int ny = get<1>(t) + dy[i];
            int color = get<2>(t);
            int distance = get<3>(t);

            if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
            if ((visit[nx][ny].second == color && visit[nx][ny].first > 0) || visit[nx][ny].second == -2 ||
                arr[nx][ny] == 0)
                continue;

            if (visit[nx][ny].second == -1) {
                visit[nx][ny] = {distance + 1, color};
                q.emplace(nx, ny, color, distance + 1);
            } else {
                if (visit[nx][ny].second != color && visit[nx][ny].first == distance + 1) {
                    flower++;
                    visit[nx][ny] = {-2, -2};
                }
            }
        }
    }

    sum = max(sum, flower);
}

void recursive(int idx, int r, int g) {
    if (r + g == G + R) {
        bfs();
        return;
    }

    if (v.size() - idx < (R - r) + (G - g)) return;

    for (int i = idx; i < v.size(); ++i) {
        if (check[v[i].first][v[i].second]) continue;
        check[v[i].first][v[i].second] = true;
        if (R > r) {
            ans.emplace_back(v[i].first, v[i].second, 0);
            recursive(i + 1, r + 1, g);
            ans.pop_back();
        }
        if (G > g) {
            ans.emplace_back(v[i].first, v[i].second, 1);
            recursive(i + 1, r, g + 1);
            ans.pop_back();
        }
        check[v[i].first][v[i].second] = false;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> M >> G >> R;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cin >> arr[i][j];
            if (arr[i][j] == 2) v.emplace_back(i, j);
        }
    }

    recursive(0, 0, 0);
    cout << sum;
    return 0;
}