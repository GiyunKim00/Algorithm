#include <iostream>
#include <vector>

using namespace std;

void rotate_matrix(vector<vector<int>>& arr, int R) {
    const int n = static_cast<int>(arr.size());
    const int m = static_cast<int>(arr[0].size());

    const int layers = min(n, m) / 2;

    for (int layer = 0; layer < layers; ++layer) {
        vector<int> v;

        for (int col = layer; col < m - layer; ++col) // top
            v.push_back(arr[layer][col]);

        for (int row = layer + 1; row < n - layer - 1; ++row) // right
            v.push_back(arr[row][m - layer - 1]);

        for (int col = m - layer -1; col >= layer; --col) // bottom
            v.push_back(arr[n - layer - 1][col]);

        for (int row = n - layer - 2; row > layer; --row) // left
            v.push_back(arr[row][layer]);

        const int len = static_cast<int>(v.size()), shift = R % len;
        vector<int> rotate(len);

        int idx = 0;

        for (int i = 0; i < len; ++i)
            rotate[i] = v[(i + shift) % len];

        for (int col = layer; col < m - layer; ++col) // top
            arr[layer][col] = rotate[idx++];

        for (int row = layer + 1; row < n - layer - 1; ++row) // right
            arr[row][m - layer - 1] = rotate[idx++];

        for (int col = m - layer -1; col >= layer; --col) // bottom
            arr[n - layer - 1][col] = rotate[idx++];

        for (int row = n - layer - 2; row > layer; --row) // left
            arr[row][layer] = rotate[idx++];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<vector<int>> arr = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9,10,11,12},
        {13,14,15,16}
    };

    rotate_matrix(arr, 2);

    for (const auto& row : arr) {
        for (const int &x : row) cout << x << ' ';
        cout << '\n';
    }

    return 0;
}