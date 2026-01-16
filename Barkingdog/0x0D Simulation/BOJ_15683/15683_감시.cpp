#include <iostream>
#include <vector>

using namespace std;
int N, M, sum;
int arr[8][8];
int ans[8][8];
vector<pair<int, int>> v;

void default_watch(int x, int y, bool mode, int dir) {
    if (dir == 0) {
        while (true) {
            x++;
            if (x < 0 || x >= N) break;
            if (arr[x][y] == 6) break;
            if (!mode) ans[x][y]++;
            else ans[x][y]--;
        }
    } else if (dir == 1) {
        while (true) {
            y++;
            if (y < 0 || y >= M) break;
            if (arr[x][y] == 6) break;
            if (!mode) ans[x][y]++;
            else ans[x][y]--;
        }
    } else if (dir == 2) {
        while (true) {
            x--;
            if (x < 0 || x >= N) break;
            if (arr[x][y] == 6) break;
            if (!mode) ans[x][y]++;
            else ans[x][y]--;
        }
    } else {
        while (true) {
            y--;
            if (y < 0 || y >= M) break;
            if (arr[x][y] == 6) break;
            if (!mode) ans[x][y]++;
            else ans[x][y]--;
        }
    }
}

void watch(int x, int y, int mode, int dir, bool erase) {
    if (mode == 1) {
        if (dir == 0) default_watch(x, y, erase, 0);
        else if (dir == 1) default_watch(x, y, erase, 1);
        else if (dir == 2) default_watch(x, y, erase, 2);
        else default_watch(x, y, erase, 3);
    } else if (mode == 2) {
        if (dir == 0) {
            default_watch(x, y, erase, 0);
            default_watch(x, y, erase, 2);
        } else {
            default_watch(x, y, erase, 1);
            default_watch(x, y, erase, 3);
        }
    } else if (mode == 3) {
        if (dir == 0) {
            default_watch(x, y, erase, 0);
            default_watch(x, y, erase, 1);
        } else if (dir == 1) {
            default_watch(x, y, erase, 1);
            default_watch(x, y, erase, 2);
        } else if (dir == 2) {
            default_watch(x, y, erase, 2);
            default_watch(x, y, erase, 3);
        } else {
            default_watch(x, y, erase, 3);
            default_watch(x, y, erase, 0);
        }
    } else if (mode == 4) {
        if (dir == 0) {
            default_watch(x, y, erase, 3);
            default_watch(x, y, erase, 0);
            default_watch(x, y, erase, 1);
        } else if (dir == 1) {
            default_watch(x, y, erase, 0);
            default_watch(x, y, erase, 1);
            default_watch(x, y, erase, 2);
        } else if (dir == 2) {
            default_watch(x, y, erase, 1);
            default_watch(x, y, erase, 2);
            default_watch(x, y, erase, 3);
        } else {
            default_watch(x, y, erase, 2);
            default_watch(x, y, erase, 3);
            default_watch(x, y, erase, 0);
        }
    } else {
        default_watch(x, y, erase, 0);
        default_watch(x, y, erase, 1);
        default_watch(x, y, erase, 2);
        default_watch(x, y, erase, 3);
    }
}

void recursive(int idx) {
    if (idx == v.size()) {
        int cnt = 0;
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < M; ++j) {
                if (ans[i][j] > 0) cnt++;
            }
        }

        sum = max(sum, cnt);
        return;
    }


    int x = v[idx].first, y = v[idx].second;
    if (arr[x][y] == 2) {
        for (int j = 0; j < 2; ++j) {
            watch(x, y, 2, j, false);
            recursive(idx + 1);
            watch(x, y, 2, j, true);
        }
    } else if (arr[x][y] == 5) {
        watch(x, y, 5, 5, false);
        recursive(idx + 1);
        watch(x, y, 5, 5, true);
    } else {
        for (int j = 0; j < 4; ++j) {
            watch(x, y, arr[x][y], j, false);
            recursive(idx + 1);
            watch(x, y, arr[x][y], j, true);
        }
    }

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> M;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cin >> arr[i][j];
            if (arr[i][j] >= 1) {
                if (arr[i][j] < 6) v.emplace_back(i, j);
                ans[i][j] = 1;
            }
        }
    }

    recursive(0);
    cout << N * M - sum;
    return 0;
}