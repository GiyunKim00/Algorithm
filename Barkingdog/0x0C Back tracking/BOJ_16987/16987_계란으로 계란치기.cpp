#include <iostream>
#include <vector>

using namespace std;
int N, ans;
vector<pair<int, int>> arr;

/**
 * 지문이 길어 문제를 제대로 읽지 않고 풀이하면 놓치는 문제임.
 * 계란을 1개 치면 무조건 다른 계란을 든다는 걸 모르고, 손에 쥐고 있는 계란이 깨질 때까지 치는 줄 알고 쩔쩔맸음.
 * 하나를 치면 무조건 다음 idx로 넘어가고, 쳤던 계란은 원상 복구한 뒤 다음 계란을 치도록 구성함.
 * 손에 쥐고 있는 계란을 제외한 나머지 계란이 모두 깨져있다면 다음 idx로 이동하도록 했음.
 * @param idx
 * @param total_broken
 */
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