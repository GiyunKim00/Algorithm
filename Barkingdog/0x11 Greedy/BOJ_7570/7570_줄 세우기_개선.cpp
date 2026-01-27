#include <iostream>

using namespace std;

int arr[1000001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, a, ans = 0;
    cin >> n;
    /**
     * 3 1 2 5 4 6 7로 선다고 가정하자.
     * 연속된 오름차순은 아래와 같음.
     *  - 1 2
     *  - 5 6 7
     *  최대 길이는 5 6 7인 3임.
     *  그럼 먼저 4를 가장 앞으로 보내고, 그 이후 3, 2, 1 순으로 앞으로 보내면 1 - 7까지의 오름차순이 완성됨. 총 4번 움직임.
     *  즉, 전체 배열 길이 - 최대 연속 오름차순 = 답
     * 연속된 오름차순이란, 줄을 앞에서 뒤로 선다는 논리에 기반함.
     * 1 2 5는 왜 불가능한가? 3이 이미 앞에 섰기에 중간이 비기 때문.
     * 5, 6, 7은? 중간에 4가 껴있으나 4를 움직이기만 하면 5, 6, 7은 움직일 필요가 없이 제대로 줄을 선 것이 되기 때문.
     */
    for (int i = 0; i < n; ++i) {
        cin >> a;
        if (arr[a - 1]) arr[a] = arr[a - 1] + 1;
        else arr[a] = 1;
        ans = max(ans, arr[a]);
    }

    cout << n - ans;
    return 0;
}