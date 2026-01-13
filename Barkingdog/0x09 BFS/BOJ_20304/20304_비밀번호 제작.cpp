#include <iostream>
#include <queue>

using namespace std;

int N, M;
int arr[100000];

int countBitsSet(int n) {
    int count = 0;
    while (n) {
        count += n & 1;
        n >>= 1;
    }
    return count;
}

int bfs(int k) {
    int cnt = INT_MAX;
    for(auto i : arr) cnt = min(cnt, i^k);
    return countBitsSet(cnt);
}

int main() {
    int ans = 0;
    cin >> N >> M;
    for(int i = 0; i<M; ++i) cin >> arr[i];

    for(int i = 1; i<=N; ++i){
        ans = max(ans, bfs(i));
    }
    cout << ans;
}