#include <iostream>
#include <queue>
using namespace std;
int n, m;
int p[501];

void bfs(const int case_num, const vector<int>* arr) {
    int cnt = 0;
    for (int i = 1; i <= n; ++i){
        if (p[i]) continue;
        bool check = true;
        queue<int> q;
        cnt++;
        p[i] = i;
        q.push(i);
        while (!q.empty() && check){
            const int k = q.front();
            q.pop();
            for (auto t : arr[k]){
                if (p[k] == t) continue;
                if (p[t]){
                    check = false;
                    cnt--;
                    break;
                }
                q.push(t);
                p[t] = k;
            }
        }
    }
    cout << "Case " << case_num << ": ";
    if (cnt == 0) cout << "No trees.\n";
    else if (cnt == 1) cout << "There is one tree.\n";
    else cout << "A forest of " << cnt << " trees.\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int case_num = 1;

    while (true){
        cin >> n >> m;
        if (n == 0) break;
        vector<int> arr[n + 1];
        fill_n(p, n+1, 0);
        while (m--){
            int a, b;
            cin >> a >> b;
            arr[a].push_back(b);
            arr[b].push_back(a);
        }

        bfs(case_num++, arr);
    }


    return 0;
}