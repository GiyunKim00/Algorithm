#include <iostream>

using namespace std;
int N, M;

enum Direction {
    UP, DOWN, RIGHT, LEFT
};

void recursive(int n, int cnt, int x, int y, Direction dir) {
    if (n == 1) {
        cout << x << " " << y;
        return;
    }

    int half = n / 2;
    int area = half * half;

    if (dir == UP) {
        if (cnt <= M && M < cnt + area) recursive(half, cnt, x, y, RIGHT);
        else if (cnt + area <= M && M < cnt + 2 * area) recursive(half, cnt + area, x, y + half, UP);
        else if (cnt + 2 * area <= M && M < cnt + 3 * area) recursive(half, cnt + 2 * area, x + half, y + half, UP);
        else recursive(half, cnt + 3 * area, x + half, y, LEFT);
    } else if (dir == RIGHT) {
        if (cnt <= M && M < cnt + area) recursive(half, cnt, x, y, UP);
        else if (cnt + area <= M && M < cnt + 2 * area) recursive(half, cnt + area, x + half, y, RIGHT);
        else if (cnt + 2 * area <= M && M < cnt + 3 * area) recursive(half, cnt + 2 * area, x + half, y + half, RIGHT);
        else recursive(half, cnt + 3 * area, x, y + half, DOWN);
    } else if (dir == LEFT) {
        if (cnt <= M && M < cnt + area) recursive(half, cnt, x + half, y + half, DOWN);
        else if (cnt + area <= M && M < cnt + 2 * area) recursive(half, cnt + area, x, y + half, LEFT);
        else if (cnt + 2 * area <= M && M < cnt + 3 * area) recursive(half, cnt + 2 * area, x, y, LEFT);
        else recursive(half, cnt + 3 * area, x + half, y, UP);
    } else {
        if (cnt <= M && M < cnt + area) recursive(half, cnt, x + half, y + half, LEFT);
        else if (cnt + area <= M && M < cnt + 2 * area) recursive(half, cnt + area, x + half, y, DOWN);
        else if (cnt + 2 * area <= M && M < cnt + 3 * area) recursive(half, cnt + 2 * area, x, y, DOWN);
        else recursive(half, cnt + 3 * area, x, y + half, RIGHT);
    }
}

int main() {
    cin >> N >> M;
    recursive(N, 1, 1, 1, UP);
    return 0;
}