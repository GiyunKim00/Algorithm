#include <iostream>
#include <queue>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    queue<int> queue;
    int num;

    cin >> num;

    for (int i = 1; i <= num; ++i)
        queue.push(i);

    for (int i = 1; queue.size() != 1; ++i) {
        if (i % 2 == 1)
            queue.pop();
        else {
            int n = queue.front();
            queue.pop();
            queue.push(n);
        }
    }

    cout << queue.front();

    return 0;
}