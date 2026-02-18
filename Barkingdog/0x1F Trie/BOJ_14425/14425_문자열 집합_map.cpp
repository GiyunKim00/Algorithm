#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    unordered_map<string, bool> arr;

    int n, m, ans = 0;
    cin >> n >> m;

    while (n--){
        string s;
        cin >> s;
        arr[s] = true;
    }

    while (m--){
        string s;
        cin >> s;
        if (arr[s]) ans++;
    }

    cout << ans;

    return 0;
}