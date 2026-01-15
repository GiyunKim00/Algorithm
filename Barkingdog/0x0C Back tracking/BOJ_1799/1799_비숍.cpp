#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, ans_black, ans_white;
vector<pair<int, int>> v_black;
vector<pair<int, int>> v_white;
bool arr[10][10];
bool left_to_right[20], right_to_left[20];

/**
 * 상당히 난도있는 문제.
 * 단순히 전체 체스판 중 비숍 착수가 가능한 위치만 백트래킹하면 무조건 시간초과가 발생함.
 * 비숍은 대각선으로만 움직이므로, 체스판의 흑/백칸에 각각 놓인 비숍은 서로에게 절대 영향을 주지 않음.
 * 이에 착안하여, 검은 칸과 흰 칸에 놓일 수 있는 비숍의 최댓값을 구한 뒤 둘을 더해줌.
 * 미분리 시 최악의 가정 : 10X10 체스판일 시 2^100 ≈ 1.27 × 10^30임. pruning을 해주어도 최소 2^50 ~ 2^60.
 * 분리 시 최악의 가정  : 10X10 체스판일 시 2^50 ≈ 1.12 × 10^15임. 분리에 따른 차이가 10^15배 이상.
 *
 * 그럼 어떨 때 분리해야 할까?
 * 질문 1 : 이 선택들이 서로 절대 영향을 안 미치는 그룹이 있나?
 * 질문 2 : 제약 조건이 특정 축 / 색 / 패리티 / 연결 요소 안에서만 작동하나?
 * 질문 3 : 결과가 합으로 표현될 수 있나?
 * 3개 다 YES면 무조건 분리
 *
 * 분리가 안 되는 경우 : 기존대로 pruning / 순서 변경 / 휴리스틱으로 진행.
 *
 * @param idx 현재 처리 중인 비숍 착수 가능 칸.
 * @param v 체스판의 흑/백 칸에 따른 배열 입력.
 * @param ans 체스판의 흑/백칸에 따른 정답 변수.
 * @param total_count 현재 체스판에 놓인 비숍의 개수.
 */
void recursive(int idx, vector<pair<int, int>> &v, int &ans, int total_count) {
    if (total_count + (int) v.size() - idx <= ans) return;

    if (idx == v.size()) {
        ans = max(ans, total_count);
        return;
    }

    int x = v[idx].first, y = v[idx].second;
    if (!left_to_right[x - y + N - 1] && !right_to_left[x + y]) {
        left_to_right[x - y + N - 1] = right_to_left[x + y] = true;
        recursive(idx + 1, v, ans, total_count + 1);
        left_to_right[x - y + N - 1] = right_to_left[x + y] = false;
        recursive(idx + 1, v, ans, total_count);
    } else {
        recursive(idx + 1, v, ans, total_count);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> arr[i][j];
            if (arr[i][j] == 1) {
                if ((i + j) % 2) v_white.emplace_back(i, j);
                else v_black.emplace_back(i, j);
            }
        }
    }

    recursive(0, v_black, ans_black, 0);
    for (int i = 0; i < 20; ++i) left_to_right[i] = right_to_left[i] = false;
    recursive(0, v_white, ans_white, 0);
    cout << ans_white + ans_black;

    return 0;
}