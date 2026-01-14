#include <iostream>
#include <vector>

using namespace std;

void recursive(vector<int> &arr, vector<int> &ans, vector<bool> &visit, int n) {
    if (n == 6) {
        for (int i = 0; i < 6; ++i)
            cout << ans[i] << " ";
        cout << "\n";

        return;
    }

    for (auto i: arr) {
        if (visit[i]) continue;
        if (!ans.empty() && ans.back() > i) continue;
        visit[i] = true;
        ans.push_back(i);
        recursive(arr, ans, visit, n + 1);
        ans.pop_back();
        visit[i] = false;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    while (true) {
        int N, t;
        cin >> N;
        if (!N) break;

        vector<int> arr, ans;
        vector<bool> visit(50, false);
        for (int i = 0; i < N; ++i) {
            cin >> t;
            arr.push_back(t);
        }

        recursive(arr, ans, visit, 0);
        cout << "\n";
    }
}