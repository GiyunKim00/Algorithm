#include <iostream>
#include <queue>
#include <climits>

using namespace std;

queue<int> freq[101];
bool use[101];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, k, next_idx, cnt = 0, plugged = 0;
    priority_queue<pair<int, int>> pq;

    cin >> n >> k;

    vector<int> arr(k);

    for (int i = 0; i < k; ++i) {
        cin >> arr[i];
        freq[arr[i]].push(i);
    }

    for (auto i: arr) {
        freq[i].pop();
        next_idx = freq[i].empty() ? INT_MAX : freq[i].front();

        if (use[i]) {
            pq.emplace(next_idx, i);
            continue;
        }

        if (plugged == n) {
            while (!pq.empty() && !use[pq.top().second]) pq.pop();
            cnt++;
            use[pq.top().second] = false;
            pq.pop();
            plugged--;
        }

        use[i] = true;
        pq.emplace(next_idx, i);
        plugged++;
    }

    cout << cnt;

    return 0;
}