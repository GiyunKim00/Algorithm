#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<int> ans;

void recursive(int n) {
    if (n == M) {
        for (auto i: ans) cout << i << " ";
        cout << "\n";

        return;
    }
    for (int i = 1; i <= N; ++i) {
        if(!ans.empty() && i < ans.back()) continue;
        ans.push_back(i);
        recursive(n + 1);
        ans.pop_back();
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> M;
    recursive(0);

    return 0;
}