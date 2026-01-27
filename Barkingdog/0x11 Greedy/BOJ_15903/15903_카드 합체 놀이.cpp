#include <iostream>
#include <queue>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t, m, a;
    long long int sum = 0, arr[2];
    priority_queue<long long int, vector<long long int>, greater<>> pq;

    cin >> t >> m;

    while (t--) {
        cin >> a;
        pq.push(a);
        sum += a;
    }

    while (m--) {
        for (int i = 0; i < 2; ++i) {
            arr[i] = pq.top();
            sum -= arr[i];
            pq.pop();
        }
        arr[0] += arr[1];

        for (int i = 0; i < 2; ++i) {
            pq.push(arr[0]);
            sum += arr[0];
        }
    }

    cout << sum;

    return 0;
}