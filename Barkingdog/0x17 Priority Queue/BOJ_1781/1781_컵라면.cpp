#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, ans = 0;
    cin >> n;
    vector<pair<int, int> > arr(n);
    priority_queue<int, vector<int>, greater<>> list;

    /**
     * deadline 기준 오름차순 정렬
     */
    for (int i = 0; i < n; ++i) cin >> arr[i].first >> arr[i].second;
    sort(arr.begin(), arr.end());

    /**
     * min_heap에 숙제를 push.
     * 이 때, 해당 데드라인보다 queue에 들어가있는 숙제가 많다? 그럼 다 못 쳐낸다는 뜻.
     * 그럼 보상이 가장 작은 숙제 하나를 pop함.
     * 따라서, 데드라인 동안 해당 기간만큼 가치 높은 숙제를 최대한 하도록 구성함.
     */
    for (const auto [fst, snd]: arr) {
        list.push(snd);
        if (fst < static_cast<int>(list.size())) list.pop();
    }

    while (!list.empty()) {
        ans += list.top();
        list.pop();
    }

    cout << ans;

    return 0;
}