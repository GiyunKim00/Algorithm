#include <iostream>
#include <vector>

using namespace std;
int n, m;
vector<int> ans;

void recursive(const int k, const int size) {
    if (size == m) {
        for (const auto i: ans) cout << i << " ";
        cout << "\n";
        return;
    }

    for (int i = k; i <= n; ++i) {
        ans.push_back(i);
        recursive(i, size + 1);
        ans.pop_back();
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    recursive(1, 0);

    return 0;
}
