#include <iostream>
#include <queue>

using namespace std;

vector<int> arr[1000001];
int dp[1000001][2];
bool visit[1000001];

/**
 * [Tree DP]
 * 트리를 BFS/DFS로 순회하며 점화식을 활용해 해를 찾아나가는 방식.
 *
 * DFS를 활용했으며, 점화식은 하기 설명과 같음.
 *  0. 내가 Early Adopter라면 dp[idx][1] = 1;, 아니라면 dp[idx][0] = 0;으로 시작.
 *  1. 내(idx)가 Early Adopter가 아니라면 -> 내 자식(child)은 모두 Early Adopter이어야만 함.
 *     => dp[idx][0] += dp[child][1];
 *  2. 내가 Early Adopter라면 -> 내 자식은 Early Adopter이거나, 아니어도 되므로 자식 중 적은 숫자를 선택.
 *     => dp[idx][0] += min(dp[child][0], dp[child][1]);
 */
void dfs(const int idx) {
    visit[idx] = true;
    dp[idx][0] = 0;
    dp[idx][1] = 1;

    for (const auto i: arr[idx]) {
        if (!visit[i]) {
            dfs(i);
            dp[idx][0] += dp[i][1];
            dp[idx][1] += min(dp[i][0], dp[i][1]);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    for (int i = 0; i < n - 1; ++i) {
        int a, b;
        cin >> a >> b;
        arr[a].push_back(b);
        arr[b].push_back(a);
    }

    dfs(1);
    cout << min(dp[1][0], dp[1][1]);
    return 0;
}