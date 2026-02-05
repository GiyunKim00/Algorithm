#include <iostream>
#include <set>
#include <map>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q, idx = 1;
    map<bool, set<int>, greater<>> arr;
    cin >> n >> q;

    for (int i = 1; i <= n; ++i){
        int a;
        cin >> a;
        arr[a].insert(i);
    }

    while (q--){
        int a, b;
        cin >> a;
        if (a == 1){
            cin >> b;
            if (arr[false].find(b) == arr[false].end()){
                arr[false].insert(b);
                arr[true].erase(b);
            }
            else{
                arr[true].insert(b);
                arr[false].erase(b);
            }
        }
        else if (a == 2){
            cin >> b;
            idx = (idx - 1 + b) % n + 1;
        }
        else{
            if (arr[true].empty()) cout << "-1\n";
            else{
                auto it = arr[true].lower_bound(idx);
                if (it == arr[true].end()) it = arr[true].begin();
                int k = *it;
                if (k == idx) cout << "0\n";
                else if (k > idx) cout << k - idx << "\n";
                else cout << n - idx + k << "\n";
            }
        }
    }

    return 0;
}