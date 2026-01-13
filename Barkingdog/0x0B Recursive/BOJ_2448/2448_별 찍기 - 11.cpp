#include <iostream>
#include <vector>

using namespace std;

int N;

void recursive(vector<vector<char>> &ans, int x, int y, int n) {
    if (n == 3) {
        for (int i = x; i < x + 3; ++i) {
            for (int j = y; j < y + 5; ++j) {
                if (i == x + 1 && (j == y || j == y + 2 || j == y + 4)) continue;
                if (i == x + 2 && j != y + 2) continue;
                ans[i][j] = '*';
            }
        }

        return;
    }

    recursive(ans, x, y, n / 2);
    recursive(ans, x, y + 2 * n / 2, n / 2);
    recursive(ans, x + n / 2, y + n / 2, n / 2);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;
    vector<vector<char>> ans(N, vector<char>(2 * N - 1, ' '));
    recursive(ans, 0, 0, N);

    for (int i = N - 1; i >= 0; --i) {
        for (int j = 0; j < 2 * N - 1; ++j) cout << ans[i][j];
        cout << "\n";
    }

    return 0;
}