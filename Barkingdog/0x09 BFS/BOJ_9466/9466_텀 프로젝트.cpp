#include <iostream>
#include <vector>
#include <stack>

using namespace std;

void bfs(int x, vector<int> &arr, vector<bool> &visit, int size) {
    vector<bool> visit_tmp(size + 1);
    stack<int> s;
    s.push(x);

    while (true) {
        int t = s.top();
        if (visit[arr[t]]) break;
        if(visit_tmp[arr[t]]) {
            while(!s.empty()) {
                visit[s.top()] = true;
                if(s.top() == arr[t]) break;
                s.pop();
            }
            break;
        }
        if (arr[t] == x) {
            while (!s.empty()) {
                visit[s.top()] = true;
                s.pop();
            }
            break;
        } else if (arr[t] == t) {
            visit[t] = true;
            break;
        }
        else if (s.size() == size) break;
        else {
            visit_tmp[arr[t]] = true;
            s.push(arr[t]);
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
        vector<bool> visit(t + 1);

        for (int i = 1; i <= t; ++i) cin >> arr[i];

        for (int i = 1; i <= t; ++i) {
            if (!visit[i]) bfs(i, arr, visit, t);
        }

        for (int i = 1; i <= t; ++i) if (!visit[i]) cnt++;

        cout << cnt << "\n";
    }

    return 0;
}
