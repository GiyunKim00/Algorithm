#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    while (true) {
        int N;
        cin >> N;
        if (N == 0) break;

        long long max_area = 0;
        stack<pair<long long, long long>> s;

        for (int i = 0; i < N; ++i) {
            long long t;
            cin >> t;

            long long int start_idx = i;

            while (!s.empty() && s.top().first > t) {
                long long int height = s.top().first;
                long long int idx = s.top().second;
                long long int area = (i - idx) * height;
                if(area > max_area) max_area = area;

                s.pop();
                start_idx = idx;
            }

            s.emplace(t, start_idx);
        }

        while (!s.empty()) {
            long long int height = s.top().first;
            long long int idx = s.top().second;
            long long int area = height * (N - idx);
            if(area > max_area) max_area = area;

            s.pop();
        }

        cout << max_area << "\n";
    }
    return 0;
}

/**
 * [알고리즘 설명]
 * 모노톤 수열을 이해하고 있어야 함.
 * 단조 증가 수열을 유지하려 함. 따라서, 1 -> 4로 스택이 쌓이는 것은 용인하나,
 * 1 -> 4 -> 3이 되는 순간 4를 pop 하여 1 -> 3으로 유지해야 하며, 4에는 3이 포함되는 관계이므로 3의 idx에 4의 idx를 부여한다.
 * 이를 통해 1 -> 3 -> 3이 되는 효과를 가질 수 있다.
 * 1 3 3 4 1이 들어온다면?
 * 1(0) -> 3(1), max : 0
 * 1(0) -> 3(1) -> 3(2), max : 0
 * 1(0) -> 3(1) -> 3(2) -> 4(3), max : 0
 * 1(0) -> 3(1) -> 3(2) -> 4(3) 여기서 1이 들어오면?
 * 1(0) -> 3(1) -> 3(2) -> 4(3) -> 1(4), max = (4 - 3) * 4  : 4
 * 1(0) -> 3(1) -> 3(2) -> 1(3), max = (4 - 2) * 3  : 6
 * 1(0) -> 3(1) -> 1(2), max = (4 - 1) * 3  : 9
 * 1(0) -> 1(1), max : 9
 * 이렇게 된다고 볼 수 있음.
 * 4 0 4 3 3이라면?
 * 0(0) -> 4(1) -> 3(2)이 되면?
 * 0(0) -> 3(1), max = (2 - 1) * 4 = 4
 * 0(0) -> 3(1) -> 3(3), max : 4 상태임.
 * 빈 스택이 아니므로 계산 시작.
 * 3 * (4 - 3) = 3 < max(4)
 * 3 * (4 - 1) = 9 > max(4)
 * 따라서 max = 9
 * 이렇게 계산 가능.
*/