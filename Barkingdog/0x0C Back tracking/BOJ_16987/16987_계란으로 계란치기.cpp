#include <iostream>
#include <vector>

using namespace std;
int N, ans;
vector<pair<int, int>> arr;

void recursive(int idx, int total_broken) {
    if (idx == N) {
        ans = max(ans, total_broken);
        return;
    }

    if (arr[idx].first <= 0) {
        recursive(idx + 1, total_broken);
        return;
    }

    bool hit = false;
    for (int i = 0; i < N; ++i) {
        if (i == idx || arr[i].first <= 0) continue;
        hit = true;
        int broken_egg = total_broken, hitting_egg = arr[idx].first, hitted_egg = arr[i].first;
        arr[i].first -= arr[idx].second;
        arr[idx].first -= arr[i].second;

        if (arr[i].first <= 0) broken_egg++;
        if (arr[idx].first <= 0) broken_egg++;
        recursive(idx + 1, broken_egg);

        arr[i].first = hitted_egg;
        arr[idx].first = hitting_egg;
    }

    if (!hit) recursive(idx + 1, total_broken);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int a, b;
    cin >> N;
    for (int i = 0; i < N; ++i) {
        cin >> a >> b;
        arr.emplace_back(a, b);
    }

    recursive(0, 0);

    cout << ans;

    return 0;
}