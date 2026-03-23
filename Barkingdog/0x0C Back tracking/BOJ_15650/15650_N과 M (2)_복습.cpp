#include <iostream>
#include <vector>

using namespace std;

vector<int> ans;
bool visit[9];
int n, m;

void recursive(const int start, const int size) {
    if (size == m) {
        for (const auto i: ans) cout << i << " ";
        cout << "\n";
        return;
    }

    for (int i = start; i <= n; ++i) {
        if (!visit[i]) {
            ans.push_back(i);
            visit[i] = true;
            recursive(i, size + 1);
            ans.pop_back();
            visit[i] = false;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    recursive(1, 0);

    return 0;
}
