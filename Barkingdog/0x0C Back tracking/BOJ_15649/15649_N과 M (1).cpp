#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int N, M;

void back_tracking(int size, vector<int> ans) {
    if (size == M) {
        for (auto i: ans) cout << i << " ";
        cout << "\n";
        return;
    }

    for (int i = 1; i <= N; ++i) {
        if (find(ans.begin(), ans.end(), i) != ans.end()) continue;
        ans.push_back(i);
        back_tracking(size + 1, ans);
        ans.pop_back();
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> M;
    vector<int> ans;
    back_tracking(0, ans);
    return 0;
}