#include <iostream>

using namespace std;

int ans[1001];

int main() {
    int n;
    cin >> n;
    ans[0] = ans[1] = 1;

    for (int i = 2; i <= n; ++i) ans[i] = (ans[i-2] + ans[i-1]) % 10007;

    cout << ans[n];

    return 0;
}