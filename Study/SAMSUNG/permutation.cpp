#include <iostream>
#include <vector>

/**
 * 삼성 코딩테스트에서 주로 출제되는 문제에서 사용되는 유형을 모아두었습니다.
 * 백트래킹을 활용한 순열, 중복 순열, 조합, 중복 조합입니다.
 */

using namespace std;

vector<int> arr = {1, 2, 3, 4};
vector<int> result;

/**
 * 순열(permutaiton). 순서가 존재하며, 중복이 없습니다.
 * visit이 필요합니다.
 * @param visit 방문처리 배열
 * @param size 현재 정답 배열 크기
 * @param limit 출력 자릿수
 */
void permutation(vector<bool> &visit, const int size, const int limit) {
    if (size == limit) {
        for (const auto &i: result) cout << i << " ";
        cout << "\n";

        return;
    }

    for (int i = 0; i < arr.size(); ++i) {
        if (visit[i]) continue;
        visit[i] = true;
        result.push_back(arr[i]);
        permutation(visit, size + 1, limit);
        visit[i] = false;
        result.pop_back();
    }
}

/**
 * 중복순열(Product). 순서가 존재하며, 중복이 존재합니다.
 * 제일 단순한 형태로써 visit이 필요 없습니다.
 * @param size
 * @param limit
 */
void product(const int size, const int limit) {
    if (size == limit) {
        for (const auto &i: result) cout << i << " ";
        cout << "\n";

        return;
    }

    for (const auto &i: arr) {
        result.push_back(i);
        product(size + 1, limit);
        result.pop_back();
    }
}

/**
 * 조합(Combination). 순서가 없고, 중복도 없습니다.
 * visit을 사용하지 않으며, start가 필요합니다.
 * @param start
 * @param size
 * @param limit
 */
void combination(const int start, const int size, const int limit) {
    if (size == limit) {
        for (const auto &i: result) cout << i << " ";
        cout << "\n";

        return;
    }

    for (int i = start; i < 4; ++i) {
        result.push_back(arr[i]);
        combination(i + 1, size + 1, limit);
        result.pop_back();
    }
}

/**
 * 중복조합(combination with replacement). 순서가 없고, 중복이 있습니다.
 * @param start
 * @param size
 * @param limit
 */
void combination_with_replacement(const int start, const int size, const int limit) {
    if (size == limit) {
        for (const auto &i: result) cout << i << " ";
        cout << "\n";

        return;
    }

    for (int i = start; i < 4; ++i) {
        result.push_back(arr[i]);
        combination_with_replacement(i, size + 1, limit);
        result.pop_back();
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<bool> visit(4, false);

    permutation(visit, 0, 4);

    result.clear();
    cout << "\n------\n\n";

    product(0, 4);

    result.clear();
    cout << "\n------\n\n";

    combination(0, 0, 3);

    result.clear();
    cout << "\n------\n\n";

    combination_with_replacement(0, 0, 3);

    return 0;
}
