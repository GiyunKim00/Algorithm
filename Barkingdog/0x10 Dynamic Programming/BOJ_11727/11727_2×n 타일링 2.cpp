#include <iostream>

using namespace std;

int ans[1001];

int main() {
    int n;
    cin >> n;
    ans[1] = 1, ans[2] = 3;

    /**
     * 상당히 까다로웠음.
     * 예를 들어, 원래라면 2X1일 때 경우의 수는 1, 2X2일 때는 2임.
     * 그런데 정사각형 타일이 추가되면서 2X2일 때는 3이 됨.
     * 2X3부터 세로 타일을 a, 가로 타일 두 묶음을 b, 정사각형 타일을 c라고 할 때... aaa, ab, ba로 끝났을 것이 ac, ca가 추가됨.
     * 즉, ab, ba로 a타일의 자리 바꾸는 동일한 타입의 경우의 수가 2배가 된 것.
     * 따라서 ans[i-2] * 2를 해주어 2배로 계산함.
     */
    for (int i = 3; i <= n; ++i) ans[i] = ((ans[i - 2]) * 2 + ans[i - 1]) % 10007;

    cout << ans[n];

    return 0;
}