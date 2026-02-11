#include <iostream>
#include <vector>
using namespace std;

/**
 * [2차원 구간 합]
 * n × n 배열이 주어지고, 직사각형 영역의 합을 여러 번 물어볼 때 사용한다.
 *
 * [로직]
 * prefix[i][j] = (1,1)부터 (i,j)까지의 모든 합으로 정의한다.
 * prefix[i][j] = arr[i][j]
 *  + prefix[i-1][j]     // 직사각형의 위쪽
 *  + prefix[i][j-1]     // 직사각형의 왼쪽
 *  - prefix[i-1][j-1];  // 겹친 영역
 *
 * 위 + 왼쪽을 더하면 왼쪽 위가 두 번 더해지므로 한 번 빼줌.
 * 다시 말해,
 * 1 2
 * 3 4
 * 가 있을 때 전체 넓이를 구하고 싶다면?, arr[i][j] = 4, prefix[i-1][j] = 3, prefix[i][j-1] = 4, prefix[1][1] = 1
 * 4 + 3 + 4 - 1을 해줌으로써 10을 구할 수 있음. 즉, 1,2(가로) 더하고 1,3(세로) 더히고 4 더한 뒤, 중복으로 더해진 1을 한 번 빼준 것.
 */
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, sum = 0;
    cin >> n >> m;

    vector<vector<int> > prefix_sum(n + 1, vector<int>(n + 1)), arr(n + 1, vector<int>(n + 1));

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> arr[i][j];
            prefix_sum[i][j] = arr[i][j] + prefix_sum[i - 1][j] + prefix_sum[i][j - 1] - prefix_sum[i - 1][j - 1];
        }
    }

    while (m--) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        sum = prefix_sum[x2][y2] - prefix_sum[x1 - 1][y2] - prefix_sum[x2][y1 - 1] + prefix_sum[x1 - 1][y1 - 1];
        cout << sum << "\n";
    }

    return 0;
}