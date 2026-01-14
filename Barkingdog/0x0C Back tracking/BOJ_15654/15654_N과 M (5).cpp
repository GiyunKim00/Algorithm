#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
bool visit[10001];
vector<int> arr;
vector<int> ans;

void recursive(int n) {
    if (n == M) {
        for (auto i: ans) cout << i << " ";
        cout << "\n";
        return;
    }

    for (auto i: arr) {
        if(visit[i]) continue;
        visit[i] = true;
        ans.push_back(i);
        recursive(n+1);
        ans.pop_back();
        visit[i] = false;
    }
}

int main() {
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