#include <iostream>
#include <vector>

using namespace std;
int N, M, K;
vector<vector<bool>> ans(40, vector<bool>(40, false));

vector<vector<int>> rotate(vector<vector<int>> &arr) {
    int h = arr.size();
    int w = arr[0].size();

    vector<vector<int>> r_arr(w, vector<int>(h));

    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) r_arr[j][h - i - 1] = arr[i][j];
    }

    return r_arr;
}

bool is_available(vector<vector<int>> &arr) {
    int h = arr.size();
    int w = arr[0].size();
    for (int i = 0; i <= N - h; ++i) {
        for (int j = 0; j <= M - w; ++j) {
            bool check = true;
            for (int x = 0; x < h && check; ++x) {
                for (int y = 0; y < w; ++y) {
                    if (arr[x][y] && ans[x + i][y + j]) {
                        check = false;
                        break;
                    }
                }
            }
            if (check) {
                for (int x = 0; x < h; ++x) {
                    for (int y = 0; y < w; ++y) if (arr[x][y]) ans[i + x][j + y] = true;
                }
                return true;
            }
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int x, y, cnt = 0;
    cin >> N >> M >> K;

    while (K--) {
        cin >> x >> y;
        vector<vector<int>> t(x, vector<int>(y, 0));

        for (int i = 0; i < x; ++i) {
            for (int j = 0; j < y; ++j) cin >> t[i][j];
        }

        vector<vector<int>> arr = t;
        for (int i = 0; i < 4; ++i) {
            if (is_available(arr)) break;
            arr = rotate(arr);
        }
    }
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) if (ans[i][j]) cnt++;
    }

    cout << cnt;

    return 0;
}