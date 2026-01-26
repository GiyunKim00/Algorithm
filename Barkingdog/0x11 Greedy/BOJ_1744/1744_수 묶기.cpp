#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(int& a, int& b) {
    return a > b;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, sum = 0, cnt = 0;
    cin >> n;
    vector<int> arr(n);

    for (int i = 0; i < n; ++i) cin >> arr[i];

    sort(arr.begin(), arr.end(), compare);

    int idx = 0;
    for (; idx < n && arr[idx] > 0; ++idx){
        cnt++;
        if (cnt == 2){
            sum += max(arr[idx] * arr[idx - 1], arr[idx] + arr[idx - 1]);
            cnt = 0;
        }
    }

    if (cnt == 1) sum += arr[idx - 1];
    cnt = 0;
    for (int i = n - 1; i >= idx; --i){
        cnt++;
        if (cnt == 2){
            sum += arr[i] * arr[i + 1];
            cnt = 0;
        }
    }

    if (cnt == 1) sum += arr[idx];

    cout << sum;
    return 0;
}