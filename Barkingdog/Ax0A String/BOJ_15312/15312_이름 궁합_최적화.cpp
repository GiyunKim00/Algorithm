#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    const int alphabet[26] = {3, 2, 1, 2, 3, 3, 2, 3, 3, 2, 2, 1, 2, 2, 1, 2, 2, 2, 1, 2, 1, 1, 1, 2, 2, 1};

    string a, b;
    cin >> a >> b;

    int idx = 0;
    const int size = a.size() *2;

    vector<int> ans(size);

    for (const auto &i: a) {
        ans[idx] = alphabet[i - 'A'];
        idx += 2;
    }

    idx = 1;

    for (const auto &i: b) {
        ans[idx] = alphabet[i - 'A'];
        idx += 2;
    }

    int limit = size;

    for (int i = 1; i < size - 1; ++i) {
        for (int j = 1; j < limit; ++j)
            ans[j - 1] = (ans[j - 1] + ans[j]) % 10;
        limit--;
    }

    cout << ans[0] << ans[1];

    return 0;
}