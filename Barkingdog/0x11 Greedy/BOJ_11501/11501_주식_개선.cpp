#include <iostream>
#include <vector>

using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, t;
    cin >> n;

    while (n--){
        long long int sum = 0;
        int max_val;

        cin >> t;

        vector<int> arr(t);

        for (int i = 0; i < t; ++i) cin >> arr[i];
        max_val = arr[t - 1];

        for (int i = t - 2; i >= 0; --i){
            if (max_val >= arr[i]) sum += max_val - arr[i];
            else max_val = arr[i];
        }

        cout << sum << "\n";
    }
}
