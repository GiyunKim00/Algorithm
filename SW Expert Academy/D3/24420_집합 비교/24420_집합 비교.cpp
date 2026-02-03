#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool is_subset(vector<int> &a, vector<int> &b) {
    int i = 0, j = 0;
    while (i < a.size()) {
        if (a[i] == b[j]) {
            i++;
            j++;
        } else if (a[i] > b[j]) j++;
        else return false;
    }

    return true;
}

int main() {
    int test_case;
    int T;
    cin >> T;

    for (test_case = 1; test_case <= T; ++test_case) {
        int a, b;
        cin >> a >> b;
        vector<int> arr_a(a), arr_b(b);

        for (int i = 0; i<a; ++i) cin >> arr_a[i];
        for (int i = 0; i<b; ++i) cin >> arr_b[i];

        sort(arr_a.begin(), arr_a.end());
        sort(arr_b.begin(), arr_b.end());

        if (a > b) {
            if (is_subset(arr_b, arr_a)) cout << ">\n";
            else cout << "?\n";
        } else if (a < b) {
            if (is_subset(arr_a, arr_b)) cout << "<\n";
            else cout << "?\n";
        } else {
            if (arr_a == arr_b) cout << "=\n";
            else cout << "?\n";
        }
    }

    return 0;
}