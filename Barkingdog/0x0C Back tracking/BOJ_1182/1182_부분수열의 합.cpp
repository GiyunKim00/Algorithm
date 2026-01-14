#include <iostream>

using namespace std;

int N, S, ans;
int arr[20];

void recursive(int idx, int sum) {
    if (idx == N) {
        if (sum == S) ans++;
        return;
    }
    recursive(idx + 1, sum + arr[idx]);
    recursive(idx + 1, sum);
}

int main() {
    cin >> N >> S;
    for (int i = 0; i < N; ++i) cin >> arr[i];
    recursive(0, 0);
    if (S == 0) ans--;
    cout << ans;

    return 0;
}