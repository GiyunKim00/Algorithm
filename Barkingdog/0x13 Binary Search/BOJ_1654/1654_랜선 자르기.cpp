#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int k, n, max_value = 0;
vector<int> arr;

int bs() {
    long long int s = 1, e = max_value, ans = 0;

    /**
     * 최댓값, 최솟값 찾는 이분탐색 문제.
     *
     * 본 문제는 랜선의 길이가 '최대'가 되어야 함.
     * if (가능(mid)) { -> mid가 조건을 만족한다면 ans에 저장해두고, 최댓값을 찾고자 s를 mid + 1함.
     *    ans = mid;
     *    s = mid + 1;   <->  e = mid - 1 (최솟값일 때, 최솟값을 찾고자 e를 mid - 1함.)
     * } else e = mid - 1;   <-> s = mid + 1 (최솟값일 때)
     */
    while (s <= e) {
        long long int sum = 0;
        long long int mid = (s + e) / 2;
        for (auto i: arr) sum += i / mid;
        if (sum >= n) {
            ans = mid;
            s = mid + 1;
        } else e = mid - 1;
    }

    return ans;
}

int main() {
    int a;
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> k >> n;


    for (int i = 0; i < k; ++i) {
        cin >> a;
        arr.push_back(a);
        max_value = max(max_value, a);
    }

    cout << bs();

    return 0;
}
