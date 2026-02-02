#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, ans = INT_MAX, s = 0, covered = 0;
    cin >> n >> m;
    vector<pair<int, int>> arr(n * m);
    vector visit(n, 0);

    for (int i = 0; i < n; ++i){
        for (int j = 0; j < m; ++j){
            cin >> arr[i * m + j].first;
            arr[i * m + j].second = i;
        }
    }

    sort(arr.begin(), arr.end());

    for (int e = 0; e < n * m; ++e){
        if (!visit[arr[e].second]) covered++;
        visit[arr[e].second]++;

        while (covered == n){
            ans = min(ans, arr[e].first - arr[s].first);
            if (ans == 0){
                cout << 0;
                return 0;
            }
            visit[arr[s].second]--;
            if (!visit[arr[s++].second]) covered--;
        }
    }

    cout << ans;
    return 0;
}