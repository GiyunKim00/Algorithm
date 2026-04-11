#include <iostream>
#include <vector>

using namespace std;

void printArr(const vector<vector<int>>& arr) {
    for (const auto& row : arr) {
        for (int x : row) {
            cout << x << ' ';
        }
        cout << '\n';
    }
    cout << '\n';
}

void gravity(vector<vector<int>>& arr) {
    const int row_size = static_cast<int>(arr.size());      // row
    const int col_size = static_cast<int>(arr[0].size());   // column

    for (int col = 0; col < col_size; ++col) {
        int write = row_size - 1;  // 현재 블록이 떨어질 위치

        for (int row = row_size - 1; row >= 0; --row) {
            if (arr[row][col] == 0) continue; // 장애물이 없다면 떨어질 위치를 그대로 유지

            if (write == row) { // 만약 맨 아래에 이미 물체가 있는 경우 떨어질 위치를 한 단계 위로 조정
                --write;
                continue;
            }

            arr[write][col] = arr[row][col]; // write 위치에 물체가 낙하
            arr[row][col] = 0; // 해당 물체가 떨어졌으니 0으로 변경
            --write; // 물체가 떨어진 곳의 위부터 쌓이도록 조정
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<vector<int>> arr = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0},
        {0, 0, 1},
        {0, 1, 0}
    };

    cout << "before\n";
    printArr(arr);

    gravity(arr);

    cout << "after\n";
    printArr(arr);

    return 0;
}