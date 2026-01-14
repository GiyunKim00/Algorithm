#include <iostream>
#include <vector>

using namespace std;
int N, M;
bool visit[9];
vector<int> ans;

void recursive(int start, int n) {
    if (n == M) {
        for (auto i: ans) cout << i << " ";
        cout << "\n";
        return;
    }

    for (int i = start; i <= N; ++i) {
        if (visit[i]) continue;
        visit[i] = true;
        ans.push_back(i);
        recursive(i + 1, n + 1);
        ans.pop_back();
        visit[i] = false;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> M;
    recursive(1, 0);
    return 0;
}