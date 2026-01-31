#include <iostream>

using namespace std;

bool visit[100001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, s = 0;
    long long int ans = 0;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; ++i) cin >> arr[i];

    for (int e = 0; e < n; ++e) {
        while (visit[arr[e]]) {
            visit[arr[s]] = false;
            s++;
        }
        visit[arr[e]] = true;
        ans += e - s + 1;
    }

    cout << ans;
    return 0;
}
