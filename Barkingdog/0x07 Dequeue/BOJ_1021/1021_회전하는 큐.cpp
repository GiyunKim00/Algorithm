#include <iostream>
#include <deque>

using namespace std;

int turn_left(deque<int> *q, int target) {
    int cnt = 0;
    while (true) {
        int compare = q->front();
        if (compare == target) {
            q->pop_front();
            return cnt;
        }
        int tmp = q->back();
        q->pop_back();
        q->push_front(tmp);
        cnt++;
    }
}

int turn_right(deque<int> *q, int target) {
    int cnt = 0;
    while (true) {
        int compare = q->front();
        q->pop_front();
        if (compare == target) return cnt;
        q->push_back(compare);
        cnt++;
    }
}

int check_left(deque<int> q, int target) {
    int cnt = 0;
    while (true) {
        int compare = q.front();
        if (compare == target) return cnt;
        int tmp = q.back();
        q.pop_back();
        q.push_front(tmp);
        cnt++;
    }
}

int check_right(deque<int> q, int target) {
    int cnt = 0;
    while (true) {
        int tmp = q.front();
        if (tmp == target) return cnt;
        q.pop_front();
        q.push_back(tmp);
        cnt++;
    }

}

int main() {
    int N, M, cnt = 0;
    deque<int> q;
    cin >> N >> M;

    for (int i = 1; i <= N; ++i) q.push_back(i);

    while (M--) {
        int k;
        cin >> k;
        int left = check_left(q, k);
        int right = check_right(q, k);
        if (left <= right) cnt += turn_left(&q, k);
        else cnt += turn_right(&q, k);
    }

    cout << cnt;

    return 0;
}