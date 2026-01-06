#include <iostream>
#include <deque>
#include <queue>
#include <tuple>

using namespace std;

int N, K;
deque<int> dq;
tuple<int, int, int> visit[100001];

int bfs() {
    queue<tuple<int, int, int>> q;
    visit[N] = {-1, N, 1};
    q.emplace(-1, N, 1);

    while (!q.empty()) {
        auto t = q.front();
//        cout << "prev : " <<  get<0>(t) << ", now : " << get<1>(t) << ", cnt : " << get<2>(t) << "\n";
        q.pop();

        for (int nx: {get<1>(t) - 1, get<1>(t) + 1, 2 * get<1>(t)}) {
            if (nx < 0 || nx > K + 1) continue;
            if (get<2>(visit[nx])) continue;
            if (nx == K) {
                int now = get<1>(t);
                dq.push_front(K);
                while (true) {
                    dq.push_front(now);
                    now = get<0>(visit[now]);
                    if(now == -1) break;
                }
                return get<2>(visit[get<1>(t)]);
            }
            visit[nx] = {get<1>(t), nx, get<2>(t) + 1};
            q.emplace(get<1>(t), nx, get<2>(t) + 1);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> K;
    if(N == K) cout << "0\n" << N;
    else if(N > K) {
        cout << N-K << "\n";
        for(int i = N; i>=K; --i) cout << i << " ";
    } else {
        cout << bfs() << "\n";
        while(!dq.empty()) {
            cout << dq.front() << " ";
            dq.pop_front();
        }
    }
    return 0;
}