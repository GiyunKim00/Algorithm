#include <iostream>
#include <queue>

using namespace std;
int n, a, root;
vector<int> arr[50];
bool visit[50];

void bfs() {
    int cnt = 0;
    queue<int> q;
    q.push(root);
    visit[root] = true;

    while (!q.empty()) {
        bool check = true;
        const int k = q.front();
        q.pop();
        if (k == a) continue;
        if (arr[k].empty()) cnt++;
        else {
            for (auto i: arr[k]) {
                if (visit[i] || i == a) continue;
                q.push(i);
                visit[i] = true;
                check = false;
            }
            if (check) cnt++;
        }
    }

    cout << cnt;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;

    for (int i = 0; i < n; ++i) {
        cin >> a;
        if (a == -1) root = i;
        else arr[a].push_back(i);
    }
    cin >> a;
    arr[a].clear();
    bfs();

    return 0;
}