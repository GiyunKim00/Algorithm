#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    int r, c, idx = 0;
    cin >> s;

    int size = s.size();
    int limit = sqrt(size);
    vector<vector<char> > arr(size, vector<char>(size));

    for (int i = 1; i <= limit; ++i) {
        if (size % i == 0) {
            c = size / i;
            r = i;
        }
    }

    for (int i = 0; i < c; ++i)
        for (int j = 0; j < r; ++j) arr[i][j] = s[idx++];

    for (int i = 0; i < r; ++i)
        for (int j = 0; j < c; ++j) cout << arr[j][i];

    return 0;
}