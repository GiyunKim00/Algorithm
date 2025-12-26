#include <iostream>

using namespace std;

int cnt = 0, r, c;
bool check = false;

void divide_and_conquer(int row, int col, int size) {
    if (check) return;
    if (size == 2) {
        for (int i = row; i < row + size; ++i) {
            for (int j = col; j < col + size; ++j) {
                if (r == i && c == j) {
                    cout << cnt;
                    check = true;
                    break;
                }
                cnt++;
            }
            if (check) break;
        }
    } else {
        int s = size / 2;
        int skip = (size / 2) * (size / 2);
        if (row <= r && r < row + s && col <= c && c < col + s) divide_and_conquer(row, col, s);
        else cnt += skip;
        if (row <= r && r < row + s && col + s <= c && c < col + size) divide_and_conquer(row, col + s, s);
        else cnt += skip;
        if (row + s <= r && r < row + size && col <= c && c < col + s) divide_and_conquer(row + s, col, s);
        else cnt += skip;
        if (row + s <= r && r < row + size && col + s <= c && c < col + size) divide_and_conquer(row + s, col + s, s);
        else cnt += skip;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N >> r >> c;

    divide_and_conquer(0, 0, 1 << N);
}