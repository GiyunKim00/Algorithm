#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int arr[1001];
int dp[1001];
int prev_idx[1001];

vector<int> line;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, ans = 1, best_idx = 1;

    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> arr[i];
        dp[i] = 1;
        prev_idx[i] = i;

        for(int j = 1; j<i; ++j) if(arr[i] > arr[j]  && dp[i] < dp[j] + 1) {
            dp[i] = dp[j] + 1;
            prev_idx[i] = j;
        }

        if(ans < dp[i]){
            ans = dp[i];
            best_idx = i;
        }
    }

    int idx = best_idx;

    while(true) {
        line.push_back(arr[idx]);
        if(prev_idx[idx] == idx) break;
        idx = prev_idx[idx];
    }

    reverse(line.begin(), line.end());
    cout << ans << "\n";
    for(auto i : line) cout << i << " ";

    return 0;
}