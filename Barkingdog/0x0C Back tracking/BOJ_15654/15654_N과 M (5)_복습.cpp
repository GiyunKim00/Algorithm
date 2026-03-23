#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
vector<int> arr, ans;
bool visit[8];

void recursive(const int size) {
    if (size == m) {
        for (const auto i: ans) cout << i << " ";
        cout << "\n";

        return;
    }

    for (int i = 0; i < n; ++i) {
        if (!visit[i]) {
            ans.push_back(arr[i]);
            visit[i] = true;
            recursive(size + 1);
            ans.pop_back();
            visit[i] = false;
        }
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