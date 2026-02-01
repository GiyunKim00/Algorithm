#include <iostream>

using namespace std;

int visit[3001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, d, k, c, sum = 0, ans = 0;
    cin >> n >> d >> k >> c;

    int arr[n];

    for (int i = 0; i < n; ++i) cin >> arr[i];


    for (int i = 0; i < k; i++){
        int idx = i % n;
        if (!visit[arr[idx]]) sum++;
        visit[arr[idx]]++;
    }

    ans = sum + (visit[c] == 0);

    for (int i = 1; i < n; ++i){
        int idx = (i + k - 1) % n;
        if (!visit[arr[idx]]) sum++;
        visit[arr[idx]]++;

        if (visit[arr[i - 1]] == 1) sum--;
        visit[arr[i - 1]]--;

        ans = max(ans, sum + (visit[c] == 0));
    }

    cout << ans;

    return 0;
}