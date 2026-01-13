#include <iostream>
#include <queue>

using namespace std;
int ans = 0;
queue<pair<int, int>> q;

/**
 * 하노이 탑의 동작 원리를 잘 생각하자!
 * 목표는 start의 가장 아래에 깔려있는 큰 원판을 to로 옮기는 것이 궁극적인 목표이다.
 * 즉, 가장 큰 원판만 start에 남았을 때는 start에 원판이 1개만 남은 n == 1 상태.
 * n == 1 : start -> to
 * 위 상황이 아닐 시에는 큰 원판을 옮기기 위해 작은 원판들을 옮겨야 한다.
 * start의 작은 원판들을 mid에 옮겨둬야, 빈 to에 start의 큰 원판을 옮길 수 있다.
 * 따라서 start -> to -> mid로 생각한다.
 * 이후 큰 원판을 start -> to로 옮겼다면? mid에 있는 원판들을 start를 경유해 to로 옮겨주면 된다.
 * 따라서, mid -> start -> to.
 * n > 1 : start -> to -> mid  =>  mid -> start -> to
 * 옮기는 과정을 출력하는 것은, 큰 원판을 옮기는 것을 출력하면 된다.
 * 작은 원판들을 옮기는 것은 재귀함수로 동작시킨다.
 * @param n : 현재 원판의 개수
 * @param start
 * @param mid
 * @param to
 */
void recursive(int n, int start, int mid, int to) {
    ans++;
    if (n == 1) {
        q.emplace(start, to);
        return;
    }

    recursive(n-1, start, to, mid);
    q.emplace(start, to);
    recursive(n-1, mid, start, to);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;

    recursive(N, 1, 2, 3);
    cout << ans << "\n";
    while (!q.empty()) {
        auto t = q.front();
        cout << t.first << " " << t.second << "\n";
        q.pop();
    }
    return 0;
}