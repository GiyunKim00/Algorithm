#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int n;
    long long sum = 0, power = 1;
    const int r = 31, m = 1234567891;
    string s;

    cin >> n >> s;

    for (int i = 0; i < n; ++i){
        sum += (s[i] - 'a' + 1) * power % m;
        sum %= m;
        power = (power * r) % m;
    }

    cout << sum;

    return 0;
}
