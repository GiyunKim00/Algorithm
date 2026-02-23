#include <iostream>

using namespace std;

int ans[4000][4000];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int alphabet[26] = {3, 2, 1, 2, 3, 3, 2, 3, 3, 2, 2, 1, 2, 2, 1, 2, 2, 2, 1, 2, 1, 1, 1, 2, 2, 1};

    string a, b;
    cin >> a >> b;

    int idx = 0, size = a.size() *2;

    for (const auto &i: a) {
        ans[0][idx] = alphabet[i - 'A'];
        idx += 2;
    }

    idx = 1;

    for (const auto &i: b) {
        ans[0][idx] = alphabet[i - 'A'];
        idx += 2;
    }

    int limit = size;

    for (int i = 1; i < a.size() + b.size(); ++i) {
        for (int j = 1; j < limit; ++j) {
            ans[i][j - 1] = (ans[i - 1][j - 1] + ans[i - 1][j]) % 10;
        }
        limit--;
    }


    cout << ans[size - 2][0] << ans[size - 2][1];

    return 0;
}