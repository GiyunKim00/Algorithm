#include <iostream>
using namespace std;

struct Shark {
    int r, c, s, d;
};

int dr[5] = {0, -1, 1, 0, 0};
int dc[5] = {0, 0, 0, 1, -1};

void move_shark(Shark& shark, const int R, const int C) {
    int& r = shark.r;
    int& c = shark.c;
    int s = shark.s;
    int& d = shark.d;

    if (d == 1 || d == 2) {
        int cycle = (R > 1) ? 2 * (R - 1) : 1;
        int steps = s % cycle;

        for (int i = 0; i < steps; ++i) {
            if (r == 0 && d == 1) d = 2;
            else if (r == R - 1 && d == 2) d = 1;
            r += dr[d];
        }
    } else {
        int cycle = (C > 1) ? 2 * (C - 1) : 1;
        int steps = s % cycle;

        for (int i = 0; i < steps; ++i) {
            if (c == 0 && d == 4) d = 3;
            else if (c == C - 1 && d == 3) d = 4;
            c += dc[d];
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Shark shark = {2, 3, 8, 1};
    const int r = 4, c = 5;

    move_shark(shark, r, c);

    cout << shark.r << ' ' << shark.c << ' ' << shark.d << '\n';

    return 0;
}