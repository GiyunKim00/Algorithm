#include <iostream>
#include <vector>

using namespace std;

int N;
string ans;

void recursive(vector<vector<char>>& arr, int x, int y, int size) {
    char first = arr[x][y];
    bool check = true;

    for (int i = x; i < x + size && check; i++) {
        for (int j = y; j < y + size; j++) {
            if (arr[i][j] != first) {
                check = false;
                break;
            }
        }
    }

    if (check) {
        cout << first;
        return;
    }

    int half_size = size / 2;
    cout << "(";
    recursive(arr, x, y, half_size);
    recursive(arr, x, y + half_size, half_size);
    recursive(arr, x + half_size, y, half_size);
    recursive(arr, x + half_size, y + half_size, half_size);
    cout << ")";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;

    vector<vector<char>> arr(N, vector<char>(N, 0));
    for (int i = 0; i < N; ++i) {
        string s;
        cin >> s;
        for (int j = 0; j < N; ++j) arr[i][j] = s[j];
    }

    recursive(arr, 0, 0, N);


    return 0;
}
