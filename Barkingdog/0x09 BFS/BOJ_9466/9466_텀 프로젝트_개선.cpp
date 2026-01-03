#include <iostream>
#include <vector>
#include <stack>

using namespace std;

void dfs(int x, vector<int> &arr, vector<int> &visit, int size) {
    vector<bool> visit_tmp(size + 1);
    stack<int> s;
    s.push(x);
    visit[x] = 1;

    while (true) {
        int t = arr[s.top()];

        if (visit[t] == 2) break;
        if (visit_tmp[t]) {
            while (!s.empty()) {
                visit[s.top()] = 2;
                if (s.top() == t) break;
                s.pop();
            }
            break;
        }
        if (t == x) {
            while (!s.empty()) {
                visit[s.top()] = 2;
                s.pop();
            }
            break;
        } else if (t == s.top()) {
            visit[t] = 2;
            break;
        }
        else if (visit[t] == 1) break;
        else {
            visit[t] = 1;
            visit_tmp[t] = true;
            s.push(t);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int N;
    cin >> N;

    while (N--) {
        int t, cnt = 0;
        cin >> t;

        vector<int> arr(t + 1);
        vector<int> visit(t + 1);

        for (int i = 1; i <= t; ++i) cin >> arr[i];

        for (int i = 1; i <= t; ++i) {
            if (visit[i] == 0) dfs(i, arr, visit, t);
        }

        for (int i = 1; i <= t; ++i) if (visit[i] != 2) cnt++;

        cout << cnt << "\n";
    }

    return 0;
}
