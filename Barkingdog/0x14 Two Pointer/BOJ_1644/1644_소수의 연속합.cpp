#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, en = 2, ans = 0;
    long long int sum = 0;

    cin >> n;

    vector isPrime(n + 1, true);
    isPrime[0] = isPrime[1] = false;

    for (int i = 2; i * i <= n; i++) if (isPrime[i]) for (int j = i * i; j <= n; j += i) isPrime[j] = false;

    for (int st = 2; st <= n; ++st) {
        while (en <= n && sum < n) {
            if (isPrime[en]) sum += en;
            en++;
        }
        if (isPrime[st]) {
            if (sum == n) ans++;
            sum -= st;
        }
    }
    cout << ans;

    return 0;
}