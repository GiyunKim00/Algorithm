#include <iostream>
#include <vector>

using namespace std;

int N;
int ans[2];

void recursive(vector<vector<int>> &arr, pair<int, int> start, int size) {
    if (size == 1) {
        ans[arr[start.first][start.second]]++;
        return;
    }
    bool check = false;
    int num = arr[start.first][start.second];
    for (int i = start.first; i < start.first + size; ++i) {
        for (int j = start.second; j < start.second + size; ++j) {
            if (num != arr[i][j]) {
                check = true;
                break;
            }
            num = arr[i][j];
        }
        if (check) break;
    }

    if (check) {
        int new_size = size / 2;
        recursive(arr, {start.first, start.second}, new_size);
        recursive(arr, {start.first, start.second + new_size}, new_size);
        recursive(arr, {start.first + new_size, start.second}, new_size);
        recursive(arr, {start.first + new_size, start.second + new_size}, new_size);
    } else ans[num]++;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;
    vector<vector<int>> arr(N, vector<int>(N, 0));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) cin >> arr[i][j];
    }

    recursive(arr, {0, 0}, N);
    for (auto i: ans) cout << i << "\n";

    return 0;
}
