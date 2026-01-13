#include <iostream>
#include <vector>

using namespace std;

int N;
string ans;

void recursive(vector<vector<char>> &arr, pair<int, int> start, int size) {
    if (size == 1) {
        cout << "(" << arr[start.first][start.second] << ")";
        return;
    }
    cout << "(";
    int new_size = size / 2;
    bool check[4] = {false,};
    int cnt = 0;
    for (int k: {0, new_size}) {
        for (int l: {0, new_size}) {
            char num = arr[start.first + k][start.second + l];
            for (int i = start.first + k; i < start.first + new_size + k; ++i) {
                for (int j = start.second + l; j < start.second + new_size + l; ++j) {
                    if (num != arr[i][j]) {
                        check[cnt] = true;
                        break;
                    }
                }
                if (check[cnt]) break;
            }

            if (check[cnt]) {
                if (cnt == 0) recursive(arr, {start.first, start.second}, new_size);
                if (cnt == 1) recursive(arr, {start.first, start.second + new_size}, new_size);
                if (cnt == 2) recursive(arr, {start.first + new_size, start.second}, new_size);
                if (cnt == 3) recursive(arr, {start.first + new_size, start.second + new_size}, new_size);
            } else cout << num;

            cnt++;
        }
    }
    cout << ")";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    bool check = true;
    cin >> N;
    char checker;
    vector<vector<char>> arr(N, vector<char>(N, 0));
    for (int i = 0; i < N; ++i) {
        string s;
        cin >> s;
        for (int j = 0; j < N; ++j){
            arr[i][j] = s[j];
            checker = arr[0][0];
            if(checker != arr[i][j]) check = false;
        }

    }
    if(check) cout << checker;
    else recursive(arr, {0, 0}, N);


    return 0;
}
