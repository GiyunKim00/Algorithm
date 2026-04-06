#include <iostream>
#include <vector>

/**
 * 삼성 코딩테스트에서 주로 출제되는 문제에서 사용되는 유형을 모아두었습니다.
 * 회전 관련 메서드입니다.
 */

using namespace std;

/**
 * 시계방향 90도 도형 회전
 * @param arr 도형
 * @return 시계방향으로 90도 회전한 도형
 */
vector<vector<int> > rotate_90(const vector<vector<int> > &arr) {
    const int row_size = arr.size(), col_size = arr[0].size();
    vector<vector<int> > new_arr(col_size, vector<int>(row_size, 0));

    for (int row_idx = 0; row_idx < row_size; ++row_idx)
        for (int col_idx = 0; col_idx < col_size; ++col_idx)
            new_arr[col_idx][row_size - 1 - row_idx] = arr[row_idx][col_idx];

    return new_arr;
}

/**
 * 시계방향 180도 도형 회전
 * @param arr 도형
 * @return 시계방향으로 180도 회전한 도형
 */
vector<vector<int> > rotate_180(const vector<vector<int> > &arr) {
    const int row_size = arr.size(), col_size = arr[0].size();
    vector<vector<int> > new_arr(row_size, vector<int>(col_size, 0));

    for (int row_idx = 0; row_idx < row_size; ++row_idx)
        for (int col_idx = 0; col_idx < col_size; ++col_idx)
            new_arr[row_size - 1 - row_idx][col_size - 1 - col_idx] = arr[row_idx][col_idx];

    return new_arr;
}

/**
 * 시계방향 270도 도형 회전
 * @param arr 도형
 * @return 시계방향으로 270도 회전한 도형
 */
vector<vector<int> > rotate_270(const vector<vector<int> > &arr) {
    const int row_size = arr.size(), col_size = arr[0].size();
    vector<vector<int> > new_arr(col_size, vector<int>(row_size, 0));

    for (int row_idx = 0; row_idx < row_size; ++row_idx)
        for (int col_idx = 0; col_idx < col_size; ++col_idx)
            new_arr[col_size - 1 - col_idx][row_idx] = arr[row_idx][col_idx];

    return new_arr;
}

/**
 * 도형 내 특정 정사각형 면적만 회전
 * @param arr 배열
 * @param row_start 회전을 시작할 좌측 상단 row 좌표
 * @param col_start 회전을 시작할 좌측 상단 col 좌표
 * @param length  회전할 특정 정사각형의 한 변 길이
 */
void rotate_square(vector<vector<int> > &arr, const int row_start, const int col_start,
                   const int length) {
    vector<vector<int> > tmp = arr;

    for (int row_idx = row_start; row_idx < row_start + length; ++ row_idx) {
        for (int col_idx = col_start; col_idx < col_start + length; ++col_idx) {
            int tmp_row = row_idx - row_start, tmp_col = col_idx - col_start;
            int rotate_row = tmp_col, rotate_col = length - 1 - tmp_row;

            tmp[row_start + rotate_row][col_start + rotate_col] = arr[row_idx][col_idx];
        }
    }

    for (int row_idx = row_start; row_idx < row_start + length; ++ row_idx)
        for (int col_idx = col_start; col_idx < col_start + length; ++col_idx)
            arr[row_idx][col_idx] = tmp[row_idx][col_idx];
}

void printSquare(const vector<vector<int> > &a) {
    for (const auto &row: a) {
        for (const int x: row) {
            cout << x << ' ';
        }
        cout << '\n';
    }
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int cnt = 1;
    vector<vector<int> > arr(4, vector<int>(6, 0));

    for (int i = 0; i < 4; ++i)
        for (int j = 0; j < 6; ++j)
            arr[i][j] = cnt++;

    const vector<vector<int> > rotated_90 = rotate_90(arr);
    const vector<vector<int> > rotated_180 = rotate_180(arr);
    const vector<vector<int> > rotated_270 = rotate_270(arr);
    printSquare(arr);
    printSquare(rotated_90);
    printSquare(rotated_180);
    printSquare(rotated_270);

    rotate_square(arr, 1, 2, 2);
    printSquare(arr);
    rotate_square(arr, 1, 2, 2);
    printSquare(arr);
    rotate_square(arr, 1, 2, 2);
    printSquare(arr);
    rotate_square(arr, 1, 2, 2);
    printSquare(arr);
    return 0;
}
