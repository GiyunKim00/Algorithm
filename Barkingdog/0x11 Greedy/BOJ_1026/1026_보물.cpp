#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(int &a, int &b){
    return a > b;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, sum = 0;
    cin >> n;
    vector<int> a(n), b(n);

    for(int i = 0; i<n; ++i) cin >> a[i];
    for(int i = 0; i<n; ++i) cin >> b[i];

    sort(a.begin(), a.end());
    sort(b.begin(), b.end(), compare);

    for(int i = 0; i<n; ++i) sum += a[i] * b[i];

    cout << sum;

    return 0;
}