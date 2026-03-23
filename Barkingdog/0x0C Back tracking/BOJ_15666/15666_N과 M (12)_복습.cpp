#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
vector<int> arr, ans;

void recurisve(const int idx, const int size) {
    if (size == m) {
        for (const auto i: ans) cout << i << " ";
        cout << "\n";

        return;
    }

    int prev = 0;

    for (int i = idx; i < n; ++i) {
        if (prev && prev == arr[i]) continue;
        ans.push_back(arr[i]);
        recurisve(i, size + 1);
        prev = ans.back();
        ans.pop_back();
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    arr.reserve(n);
    ans.reserve(n);

    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        arr.push_back(a);
    }

    sort(arr.begin(), arr.end());

    recurisve(0, 0);

    return 0;
}