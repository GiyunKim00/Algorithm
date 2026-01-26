#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int n;
    long long sum = 0, power = 1;
    const int r = 31, m = 1234567891;
    string s;

    cin >> n >> s;
    /**
     * 연산자 우선순위 주의!
     * 문제를 잘 살피고, +=, *=로 접근해도 되는 문제인지 확인하기.
     */
    for (int i = 0; i < n; ++i){
        sum += (s[i] - 'a' + 1) * power % m;
        sum %= m;
        power = (power * r) % m;
    }

    cout << sum;

    return 0;
}
