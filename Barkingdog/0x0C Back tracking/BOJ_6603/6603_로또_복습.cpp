#include <iostream>
#include <vector>

using namespace std;

int n;

void recursive(const vector<int> &arr, vector<int> &ans, const int idx, const int size) {
    if (size == 6) {
        for (const auto i: ans) cout << i << " ";
        cout << "\n";

        return;
    }

    for (int i = idx; i < n; ++i) {
        ans.push_back(arr[i]);
        recursive(arr, ans, i + 1, size + 1);
        ans.pop_back();
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    while (true) {
        cin >> n;
        if (!n) break;
        vector<int> arr, ans;
        arr.reserve(n);
        ans.reserve(6);
        for (int i = 0; i < n; ++i) {
            int a;
            cin >> a;
            arr.push_back(a);
        }

        recursive(arr, ans, 0, 0);
        cout << "\n";
    }

    return 0;
}