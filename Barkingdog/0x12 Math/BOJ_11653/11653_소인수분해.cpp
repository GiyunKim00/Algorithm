#include <iostream>
#include <vector>

using namespace std;

bool prime[10000001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    for (int i = 2; i * i < n; ++i) {
        for (int j = 2; j * j < n; ++j) {
            if (prime[i * j]) continue;
            prime[i * j] = true;
        }
    }

    int idx = 2;

    while (n > idx) {
        while (n % idx == 0) {
            cout << idx << "\n";
            n /= idx;
            if (n == 0) break;
        }
        idx++;
        while (prime[idx]) idx++;
    }

    if (n != 0 && n!= 1) cout << n;
    return 0;
}