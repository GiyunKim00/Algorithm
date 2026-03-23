#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m, visit[8];
vector<int> arr, ans;

void recursive(const int size) {
    if (size == m) {
        for (const auto i: ans) cout << i << " ";
        cout << "\n";

        return;
    }
    int prev = 0;

    for (int i = 0; i < n; ++i) {
        if (prev && prev == arr[i] || visit[i]) continue;
        visit[i] = true;
        ans.push_back(arr[i]);
        recursive(size + 1);
        prev = ans.back();
        ans.pop_back();
        visit[i] = false;
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

    recursive(0);

    return 0;
}