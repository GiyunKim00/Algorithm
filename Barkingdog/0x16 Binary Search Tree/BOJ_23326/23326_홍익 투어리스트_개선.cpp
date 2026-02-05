#include <iostream>
#include <set>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q, idx = 1;
    set<int> arr;
    cin >> n >> q;

    for (int i = 1; i <= n; ++i){
        int a;
        cin >> a;
        if (a) arr.insert(i);
    }

    while (q--){
        int a, b;
        cin >> a;
        if (a == 1){
            cin >> b;
            if (arr.find(b) == arr.end()) arr.insert(b);
            else arr.erase(b);
        }
        else if (a == 2){
            cin >> b;
            idx = (idx - 1 + b) % n + 1;
        }
        else{
            if (arr.empty()) cout << "-1\n";
            else{
                auto it = arr.lower_bound(idx);
                if (it == arr.end()) cout << n - idx + *arr.begin() << "\n";
                else cout << *it - idx << "\n";
            }
        }
    }

    return 0;
}