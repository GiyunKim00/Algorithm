#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    long long cnt = 0;
    vector<int> v;
    stack<int> s1, s2;
    cin >> N;

    for (int i = 0; i < N; ++i) {
        int k;
        cin >> k;
        v.push_back(k);
    }

    reverse_iterator r_iter = v.rbegin();
    for (; r_iter != v.rend(); r_iter++) s1.push(*r_iter);

    while (!s1.empty()) {
        int k = s1.top();
        s1.pop();
        while (!s1.empty() && s1.top() < k) {
            cnt++;
            s2.push(s1.top());
            s1.pop();
        }
        while (!s2.empty()) {
            s1.push(s2.top());
            s2.pop();
        }
    }

    cout << cnt;

    return 0;
}