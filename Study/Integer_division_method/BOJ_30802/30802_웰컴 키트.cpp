#include <iostream>
#include <cmath>

using namespace std;

int shirt[6];

int main() {
    int n, t, p, t_sum = 0;
    cin >> n;

    for(int i = 0; i < 6; ++i) cin >> shirt[i];
    cin >> t >> p;

    for(auto i : shirt) t_sum += (i + t - 1) / t;

    cout << t_sum << "\n" << n / p << " " << n % p;

    return 0;
}