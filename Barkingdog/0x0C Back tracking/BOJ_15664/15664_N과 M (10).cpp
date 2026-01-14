#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
vector<int> arr, ans;
bool visit[9];

void recursive(int n) {
    if (n == M) {
        for (auto i: ans) cout << i << " ";
        cout << "\n";

        return;
    }
    int prev = -1;
    for(int i = 0; i<N; ++i) {
        if(visit[i] || prev == arr[i]) continue;
        if(!ans.empty() && ans.back() > arr[i]) continue;
        visit[i] = true;
        ans.push_back(arr[i]);
        recursive(n + 1);
        ans.pop_back();
        prev = arr[i];
        visit[i] = false;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> M;

    for (int i = 0; i < N; ++i) {
        int t;
        cin >> t;
        arr.push_back(t);
    }

    sort(arr.begin(), arr.end());

    recursive(0);

    return 0;
}