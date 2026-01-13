#include <iostream>
#include <vector>

using namespace std;

int N;

void recursive(vector<vector<char>> &arr, int x, int y, int n) {
    if (n == 3) {
        for (int i = x; i < x + 3; ++i) {
            for (int j = y; j < y + 3; ++j) {
                if (i == x + 1 && j == y + 1) continue;
                arr[i][j] = '*';
            }
        }
        return;
    }
    int new_size = n / 3;
    for (auto i: {x, x + new_size, x + 2 * new_size}) {
        for (auto j: {y, y + new_size, y + 2 * new_size}) {
            if (i == x + new_size && j == y + new_size) continue;
            recursive(arr, i, j, new_size);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;
    vector<vector<char>> arr(N, vector<char>(N, ' '));
    recursive(arr, 0, 0, N);

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cout << arr[i][j];
        }
        cout << "\n";
    }
    return 0;
}