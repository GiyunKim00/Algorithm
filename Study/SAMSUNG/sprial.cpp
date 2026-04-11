#include <iostream>
#include <vector>

using namespace std;

void printArr(const vector<vector<int> > &arr) {
    for (const auto &row: arr) {
        for (int x: row) {
            cout << x << '\t';
        }
        cout << '\n';
    }
    cout << '\n';
}

vector<vector<int> > spiral_from_center(const int n) {
    vector<vector<int> > arr(n, vector<int>(n, 0));

    int x = n / 2, y = n / 2;
    const int dx[4] = {0, 1, 0, -1}; // 좌, 하, 우, 상
    const int dy[4] = {-1, 0, 1, 0};

    int dir = 0, num = 0, dist = 1;

    while (num < n * n - 1) {
        for (int repeat = 0; repeat < 2; ++repeat) {
            for (int step = 0; step < dist; ++step) {
                x += dx[dir];
                y += dy[dir];

                if (x >= 0 && x < n && y >= 0 && y < n) arr[x][y] = ++num;
            }
            dir = (dir + 1) % 4;
        }
        dist++;
    }

    return arr;
}

vector<vector<int> > spiral_from_top_left(const int n) {
    vector<vector<int> > arr(n, vector<int>(n, 0));

    int top = 0, bottom = n - 1, right = n - 1, left = 0, num = 0;

    while (num <= n * n -1) {
        for (int i = left; i <= right; ++i)
            arr[top][i] = num++;
        top++;

        for (int i = top; i <= bottom; ++i)
            arr[i][right] = num++;
        right--;

        if (top > bottom || left > right) break;

        for (int i = right; i >= left; --i)
            arr[bottom][i] = num++;
        bottom--;

        for (int i = bottom; i >= top; --i)
            arr[i][left] = num++;
        left++;
    }

    return arr;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<vector<int> > arr1 = spiral_from_center(5);
    printArr(arr1);

    vector<vector<int> > arr2 = spiral_from_top_left(5);
    printArr(arr2);
    return 0;
}
