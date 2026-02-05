#include <iostream>
#include <queue>

using namespace std;

/**
 * priority_queue의 compare는 true를 반환해야 swap되는 구조임.
 * 따라서, 오름차순 정렬을 원할 시, a>b로 설정해야함. 즉, a가 b보다 크면 swap한다, 라는 것.
 *
 * 일반적인 STL queue의 경우 a<b가 오름차순임. priority_queue가 반대.
 */
struct compare {
    bool operator ()(const int& a, const int& b) const {
        if (abs(a) == abs(b)) return a > b;
        return abs(a) > abs(b);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    priority_queue<int, vector<int>, compare> q;
    int n, a;
    cin >> n;

    while (n--){
        cin >> a;
        if (a) q.push(a);
        else{
            if (q.empty()) cout << "0\n";
            else{
                cout << q.top() << "\n";
                q.pop();
            }
        }
    }

    return 0;
}