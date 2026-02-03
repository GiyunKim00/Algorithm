#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t, a, b, n;
    cin >> t;
    while (t--) {
        int cnt = 0;
        cin >> a >> b >> n;
        while (true) {
            if (a > b) b += a;
            else a += b;
            cnt++;
            if (a > n || b > n) {
                cout << cnt << "\n";
                break;
            }
        }
    }
    return 0;
}