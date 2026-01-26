#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct time_table {
    int start_time;
    int end_time;
};

bool compare(const time_table& a, const time_table& b) {
    if (a.start_time == b.start_time) return a.end_time > b.end_time;
    return a.start_time < b.start_time;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;

    vector<time_table> arr;
    //강의 종료 시각을 오름차순으로 정렬하는 우선순위 큐
    priority_queue<int, vector<int>, greater<>> pq;

    while (n--){
        time_table a;
        cin >> a.start_time >> a.end_time;
        arr.push_back(a);
    }

    // 강의 시작 시각 기준 오름차순 정렬
    sort(arr.begin(), arr.end(), compare);

    /**
     * [해설]
     * pq.top()은 현재 가장 이른 강의 종료 시각임.
     *
     * 문제의 본질은, 마치 비어있는 의자에 앉는 것과 같다는 것.
     * 맨 처음, 의자가 아예 없는데 앉으려는 사람이 1명 생기면, 의자를 1개 추가할 것. (pq.size() == 0 -> 1)
     * 의자에 앉아있던 사람이 떠나고, 다음 사람이 앉는다면? 의자는 1개만으로 충분.
     *
     * 그런데, 의자에 앉아있는 사람이 안 비키는데 다음 사람이 앉으려 한다면? 의자가 1개 더 필요. (pq.size() == 1 -> 2)
     * 이렇게 추가된 의자는 줄어들지 않고 유지됨. 이제 2명이 한꺼번에 앉을 수 있는 의자가 마련된 것임.
     *
     * 이 문제는 하나의 강의가 하나의 강의실만 사용하므로 if문으로 pq.pop을 처리해도 됨.
     * 즉, 1 4, 2 5인 강의가 pq에 들어있을 때 6 8인 강의가 오면? 1 4, 2 5인 강의 둘 다 끝났지만 1 4만 pop하면 됨.
     * 왜? 강의가 끝난 강의실이 2개라지만, 한 강의가 강의실 2개를 다 쓰는게 아니라. 1개만 쓰기 때문.
     *
     * 강의실을 2개씩 쓴다? 그렇다면 이야기는 달라짐. 그 때부턴 if로 pop을 관리하는 것이 아닌, while로 관리해야 함.
     * 최소 필요 강의실의 숫자는 더 이상 pq.size()가 아닌, max_class = max(max_class, pq.size());가 됨.
     */
    for (auto i : arr){
        if (!pq.empty() && pq.top() <= i.start_time) pq.pop();
        pq.push(i.end_time);
    }

    cout << pq.size();
    return 0;
}