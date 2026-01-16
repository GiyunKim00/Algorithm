#include <iostream>
#include <vector>

using namespace std;

int visit[1000000];
int ans = 1000001;

void dfs(int n, int cnt) {

    if (n == 1) {
        visit[1] = cnt;
        ans = min(ans, cnt);
        return;
    }

    if (ans <= cnt + 1) return;

    if (n % 3 == 0) {
        if (visit[n / 3] == 0 || (visit[n / 3] >= cnt + 1)) {
            int t = visit[n / 3];
            visit[n / 3] = cnt + 1;
            dfs(n / 3, cnt + 1);
            visit[n / 3] = t;
        }
    }
    if (n % 2 == 0) {
        if (visit[n / 2] == 0 || (visit[n / 2] >= cnt + 1)) {
            int t = visit[n / 2];
            visit[n / 2] = cnt + 1;
            dfs(n / 2, cnt + 1);
            visit[n / 2] = t;
        }
    }
    if (visit[n - 1] == 0 || visit[n - 1] >= cnt + 1) {
        int t = visit[n - 1];
        visit[n - 1] = cnt + 1;
        dfs(n - 1, cnt + 1);
        visit[n - 1] = t;
    }
}

int main() {
    int N;
    cin >> N;

    visit[N] = true;

    dfs(N, 0);
    cout << ans;
    return 0;
}
