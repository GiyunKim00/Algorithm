#include <iostream>

using namespace std;

int arr[501][501];
int n, m;

int dfs(int x, int y) {
    if (x < 0 || y < 0 || x >= n || y >= m) return 0;
    if (arr[x][y] == 0 || arr[x][y] == 2) return 0;
    arr[x][y] = 2;

    return 1 + dfs(x - 1, y) + dfs(x + 1, y) + dfs(x, y - 1) + dfs(x, y + 1);

}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int max_area = 0, cnt = 0;
    cin >> n >> m;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            int t;
            cin >> t;
            arr[i][j] = t;
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (arr[i][j] == 1) {
                cnt++;
                max_area = max(max_area, dfs(i, j));
            }
        }
    }

    cout << cnt << "\n" << max_area;

    return 0;
}