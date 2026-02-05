#include <iostream>
#include <queue>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, a;
    cin >> n;
    priority_queue<int, vector<int>, greater<>> q;

    for (int i = 0; i < n*n; ++i){
        cin >> a;
        q.push(a);
        /**
         * size 비교가 빈번한데 q.size()를 int로 typecasting 해주면 속도가 100ms나 단축됨.
         * 현대 CPU는 보통 signed int 비교에 최적화되어있는데, q.size()>n을 할 시 int->unsigned로 변환하게 됨.
         * 따라서 이를 줄이고자 q.size를 강제로 int typecasting하여 오버헤드를 줄이는 것.
         */
        if ((int)q.size() > n) q.pop();
    }
    cout << q.top();
}