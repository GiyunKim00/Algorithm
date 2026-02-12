#include <iostream>
#include <vector>

using namespace std;

struct edge {
    int child;
    int value;
};

int ans = 0;
vector<edge> arr[10001];

int dfs(const int idx) {
    int fst = 0, snd = 0;
    for (const auto &[child, value]: arr[idx]) {
        if (const int length = dfs(child) + value; length > fst) {
            snd = fst;
            fst = length;
        } else if (length > snd) snd = length;
    }
    ans = max(ans, fst + snd);
    return fst;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;

    cin >> n;

    for (int i = 1; i < n; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        arr[a].push_back({b, c});
    }

    dfs(1);
    cout << ans;
    return 0;
}