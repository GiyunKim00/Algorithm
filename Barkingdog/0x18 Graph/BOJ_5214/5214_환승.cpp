#include <iostream>
#include <queue>

using namespace std;

int n, k, m;

vector<int> arr[101002];
int visit[101002];

/**
 * [이분 그래프 BFS(레이어드 그래프 BFS (Layered Graph BFS)) 문제.]
 * 모든 노드 간 간선을 연결하는 일반적인 BFS로는 메모리 초과가 발생해 해결할 수 없는 문제.
 * 따라서 이분 그래프를 구성하고, 그에 따른 BFS를 수행해야만 한다.
 * 즉, 간선이 너무 많아질 때, 그 간선을 대표하는 ‘중간 노드’를 만들어 BFS하는 패턴이다.
 * 레이어드 그래프 BFS (Layered Graph BFS)라고 부르기도 한다.
 *
 * [이분 그래프란?]
 * 정점을 두 집합 U, V로 나누었을 때 모든 간선은 반드시 U의 정점과 V의 정점 사이에만 존재하는 그래프.
 * 그래프를 색칠하는 관점에서 보면 두 가지 색만으로 인접한 정점끼리 서로 다른 색을 칠할 수 있다면 이분 그래프로 볼 수 있다.
 *
 * 예를 들어,
 * - 친구 관계 그래프에서 "남자 ↔ 여자"만 연결되어 있는 구조
 * - 체스판처럼 흑백이 번갈아 연결되어 있는 구조
 * - 철도 라인이 있고, 해당 라인에 정차역이 여러 개 있는 구조
 *
 * 이분 그래프 활용 문제로는 하기 구성이 있다.
 * 1. 최대 매칭 알고리즘 (Bipartite Matching)
 *   - 예: 남녀 커플 매칭, 구직자 ↔ 기업 매칭 등
 * 2. 색칠 문제
 *   - 2색 문제 해결 시, 이분 그래프 조건을 만족하는지 확인
 * 3. 이분 그래프 기반 이분 탐색 문제
 *   - Bipartite Check + Union-Find 조합으로 나오는 문제들
 */
void bfs() {
    queue<int> q;
    q.push(1);
    visit[1] = 1;

    while (!q.empty()){
        const auto idx = q.front();
        q.pop();

        for (const int i : arr[idx]){
            if (visit[i]) continue;

            if (i > n) visit[i] = visit[idx];
            else visit[i] = visit[idx] + 1;

            if (i == n){
                cout << visit[i];
                return;
            }
            q.push(i);
        }
    }

    cout << "-1";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> k >> m;

    if (n == 1) cout << 1;
    else{
        for (int i = 1; i <= m; ++i){
            int a;
            for (int j = 0; j < k; ++j){
                cin >> a;
                arr[a].push_back(i + n);
                arr[i + n].push_back(a);
            }
        }

        bfs();
    }

    return 0;
}