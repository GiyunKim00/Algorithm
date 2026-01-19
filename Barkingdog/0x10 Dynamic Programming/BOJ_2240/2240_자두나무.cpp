#include <iostream>

using namespace std;

int arr[1001][32];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t, w, a, now, ans = 0;
    cin >> t >> w;

    /**
     * 시작위치가 1번 나무 아래라는 조건이 주어지므로 움직인 횟수가 홀수면 2번 나무 아래, 짝수면 1번나무 아래에 위치함을 알 수 있음.
     * 해당 시간 동안 얼만큼 움직였을 때 최대의 자두를 얻을 수 있는지에 따라 점화식을 세움.
     * 즉, 움직일 수 있는 횟수는 w이하이며 0~w번 움직였을 때 각각 얼만큼의 자두를 얻을 수 있는지 계산하면 됨.
     */
    for (int i = 1; i <= t; ++i) {
        cin >> a;
        for (int j = 1; j <= w + 1; ++j) {
            now = j % 2 == 1 ? 1 : 2;
            if(now == a) arr[i][j] = max(arr[i-1][j], arr[i-1][j-1]) + 1;
            else arr[i][j] = max(arr[i-1][j], arr[i-1][j-1]);
        }
    }
    for (int i = 1; i <= w + 1; ++i) ans = max(ans, arr[t][i]);
    cout << ans;
    return 0;
}