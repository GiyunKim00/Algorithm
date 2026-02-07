#include <iostream>
#include <queue>

using namespace std;
int dist = 0, cnt, house = 20001;
vector<int> arr[20001], visit(20001);

void bfs() {
    queue<int> q;
    q.push(1);
    visit[1] = 1;

    while (!q.empty()) {
        const int k = q.front();
        q.pop();

        for (const auto i : arr[k]) {
            if (visit[i]) continue;
            visit[i] = visit[k] + 1;
            if (visit[i] > dist) {
                dist = visit[i];
                house = i;
                cnt = 1;
            } else if (visit[i] == dist) {
                house = min(house, i);
                cnt++;
            }
            q.push(i);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    while (m--) {
        int a, b;
        cin >> a >> b;
        arr[a].push_back(b);
        arr[b].push_back(a);
    }

    bfs();

    cout << house << " " << dist - 1 << " " << cnt;

    return 0;
}