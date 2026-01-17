#include <iostream>

using namespace std;

int stair[301];
int ans[301][2];

int main() {
    int n;
    cin >> n;

    for (int i = 1; i <= n; ++i) cin >> stair[i];
    ans[1][0] = stair[1];
    ans[2][0] = stair[2];
    ans[2][1] = stair[1] + stair[2];

    /**
     * 점화식
     * - arr[i][x] => x가 0일 시 불연속임을 의미. 이는 2가지 의미가 존재.
     *  1. 두 계단을 한 번에 건너 뜀.
     *  2. 연속하여 두 계단을 올랐기에 arr[i]에 도달하려면 반드시 두 계단을 건너뛰어야 함.
     *  둘 간의 차이는,
     *      - 1번의 경우 : (i-4) -> (i-2) -> (i) 이런 식으로 연속되지 않았음에도 두 칸씩 건너뛴 것.
     *      - 2번의 경우 : (i-3) -> (i-2) -> (i) 이런 식으로 두 계단을 연속해서 밟은 뒤 두 칸을 건너뛴 것.
     *
     * - arr[i][x] => x가 1일 시 연속을 의미. 다음 번엔 무조건 점프해야 함.
     *  i-1 -> i로 오며 연속된 것임.
     *
     */
    for (int i = 3; i <= n; ++i) {
        ans[i][0] = max(ans[i - 2][0], ans[i - 2][1]) + stair[i];
        ans[i][1] = ans[i - 1][0] + stair[i];
    }

    cout << max(ans[n][0], ans[n][1]);
    return 0;
}