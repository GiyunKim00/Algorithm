#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    string a, b;
    unordered_map<string, string> arr;
    cin >> n >> m;

    while (n--) {
        cin >> a >> b;
        arr[a] = b;
    }

    while (m--) {
        cin >> a;
        cout << arr[a] << "\n";
    }

    return 0;
}