#include <iostream>
#include <queue>
#include <bit>

using namespace std;

int N, M;
bool visit[1000001];
queue<pair<int, int>> q;

/**
 * 비트 연산을 활용함.
 * 새 비밀번호와 로그인 시도 된 비밀번호 간 안전도가 1이라는 것은, 새 비밀번호와 로그인 시도된 비밀번호 간 비트열 차이가 1이라는 것.
 * 기존 비밀번호가 1010(10)이라면, 안전도가 1인 비밀번호로는 1011(11), 1000(8), 1110(14), 0010(2)가 있음.
 * BFS를 통해 로그인 시도 된 비밀번호들로부터 가장 먼 비밀번호가 안전도가 제일 높은 비밀번호임을 찾아낼 수 있음.
 * @return 안전도 최대값
 */
int bfs() {
    int ans = 0;
    int bits = __bit_width(N);

    while (!q.empty()) {
        auto t = q.front();
        q.pop();

        for (int i = 0; i < bits; i++) {
            int nx = t.first ^ (1 << i);
            if (nx < 0 || nx > N) continue;
            if (visit[nx]) continue;
            visit[nx] = true;
            q.emplace(nx, t.second + 1);
            if (t.second + 1 > ans) ans = t.second + 1;
        }
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> M;
    for (int i = 0; i < M; ++i) {
        int t;
        cin >> t;
        visit[t] = true;
        q.emplace(t, 0);
    }
    cout << bfs();
}