#include <iostream>

using namespace std;

int arr[2200][2200] = {0,};
int ans[3] = {0,};

void divide_and_conquer(int x, int y, int size) {
    bool check = false;
    int comparison_num = arr[x][y];
    for (int i = x; i < x + size; ++i) {
        for (int j = y; j < y + size; ++j) {
            if (arr[i][j] != comparison_num) {
                check = true;
                break;
            }
        }
        if (check) break;
    }

    if (check) {
        divide_and_conquer(x, y, size / 3);
        divide_and_conquer(x + size / 3, y, size / 3);
        divide_and_conquer(x + 2 * (size / 3), y, size / 3);
        divide_and_conquer(x, y + size / 3, size / 3);
        divide_and_conquer(x, y + 2 * (size / 3), size / 3);
        divide_and_conquer(x + size / 3, y + size / 3, size / 3);
        divide_and_conquer(x + size / 3, y + 2 * (size / 3), size / 3);
        divide_and_conquer(x + 2 * (size / 3), y + size / 3, size / 3);
        divide_and_conquer(x + 2 * (size / 3), y + 2 * (size / 3), size / 3);
    } else ans[++comparison_num]++;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> arr[i][j];
        }
    }

    divide_and_conquer(0, 0, N);

    for (auto i: ans) cout << i << "\n";

    return 0;
}