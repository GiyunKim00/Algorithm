#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n = 0, cur = 0;
    bool check = true;
    int arr[100001] = {0,};
    stack<int> s;
    vector<char> c;

    cin >> n;

    for (int i = 0; i < n; ++i) {
        int k = 0;
        cin >> k;
        if (arr[k] == 2) {
            cout << "NO";
            check = false;
            break;
        }
        if (cur < k) {
            for (int j = cur + 1; j <= k; ++j) {
                if (arr[j] < 1) {
                    arr[j]++;
                    c.push_back('+');
                }
            }
            arr[k]++;
            c.push_back('-');
            cur = k - 1;
        } else {
            for (int j = cur; j >= k; --j) {
                if (arr[j] != 2) {
                    arr[j]++;
                    c.push_back('-');
                }
            }
            cur = k - 1;
        }
        for(int t = 1; t<=n; ++t) cout << t << "(" << arr[t] << ") ";
        cout <<"\n";
    }

    if (check) for (auto i: c) cout << i << "\n";

    return 0;
}