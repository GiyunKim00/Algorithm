#include <iostream>
#include <stack>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int K, sum = 0;
    stack<int> s;

    cin >> K;
    while (K--) {
        int n;
        cin >> n;
        if (n == 0) {
            sum -= s.top();
            s.pop();
        } else {
            sum += n;
            s.push(n);
        }
    }
    cout << sum;
    return 0;
}