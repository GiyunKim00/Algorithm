#include <iostream>

using namespace std;

long long int A, B, C;

long long int recursive(long long int b) {
    if (b == 0) return 1 % C;
    if (b == 1) return A % C;

    long long int k = recursive(b / 2);

    if (b % 2) return (k * k % C) * A % C;
    return k * k % C;
}

int main() {
    cin >> A >> B >> C;
    cout << recursive(B);
    return 0;
}