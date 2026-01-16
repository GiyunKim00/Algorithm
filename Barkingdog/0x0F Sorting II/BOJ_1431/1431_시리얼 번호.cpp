#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(string a, string b) {
    if(a.size() == b.size()) {
        int sum_a = 0, sum_b = 0;
        for (auto i: a) if (isdigit(i)) sum_a += i - '0';
        for (auto i: b) if (isdigit(i)) sum_b += i - '0';
        if(sum_a == sum_b) {
            for (int i = 0; i < a.size(); ++i) {
                if (a[i] > b[i]) return false;
                if (a[i] < b[i]) return true;
            }
        } else return sum_a < sum_b;
    }

    return a < b;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    string s;
    cin >> n;
    vector<string> ans;
    while (n--) {
        cin >> s;
        ans.push_back(s);
    }

    sort(ans.begin(), ans.end(), compare);

    for (auto i: ans) cout << i << "\n";
}