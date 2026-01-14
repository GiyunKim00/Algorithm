#include <iostream>

using namespace std;

int N, S, ans;
int arr[20];
/**
 * 가지치기가 거의 없는 백트래킹 문제.
 * 해당 수를 sum에 포함할 지 여부를 분기함.
 * @param idx 인덱스
 * @param sum 합계
 */
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