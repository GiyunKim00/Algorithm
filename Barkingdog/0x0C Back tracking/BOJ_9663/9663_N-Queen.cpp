#include <iostream>

using namespace std;

int N, ans;
bool up_down[15];
bool right_to_left[30];
bool left_to_right[30];

void back_tracking(int line) {
    if (line == N) {
        ans++;
        return;
    }

    for (int i = 0; i < N; ++i) {
        if (up_down[i] || right_to_left[line + i] || left_to_right[line - i + N - 1]) continue;
        up_down[i] = left_to_right[line - i + N - 1] = left_to_right[line - i + N - 1] = true;
        back_tracking(line + 1);
        up_down[i] = left_to_right[line - i + N - 1] = left_to_right[line - i + N - 1] = false;
    }
}

int main() {
    cin >> N;
    back_tracking(0);
    cout << ans;
    return 0;
}