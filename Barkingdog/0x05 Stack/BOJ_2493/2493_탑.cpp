#include <iostream>
#include <stack>

using namespace std;

struct tower {
    int location;
    int value;

    tower(int a, int b) : location(a), value(b) {}
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    stack<tower> first;
    stack<tower> second;
    int ans[500001] = {0,};
    int N;
    cin >> N;

    for (int i = 1; i <= N; ++i) {
        int k;
        cin >> k;
        first.emplace(i, k);
    }

    for (int i = 0; i < N; ++i) {
        second.push(first.top());
        first.pop();
        while (!second.empty() && !first.empty() && first.top().value > second.top().value) {
            ans[second.top().location] = first.top().location;
            second.pop();
        }
    }

    for (int i = 1; i <= N; ++i) cout << ans[i] << " ";

    return 0;
}