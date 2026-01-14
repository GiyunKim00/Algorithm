#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int R, C;
vector<char> arr, ans;
bool visit[26];

void recursive(int n) {
    if (n == R) {
        int vowel = 0, consonant = 0, check = 0;
        for (auto i: ans) {
            if (i == 'a' || i == 'e' || i == 'i' || i == 'o' || i == 'u') vowel++;
            else consonant++;
            if (vowel >= 1 && consonant >= 2) {
                check = true;
                break;
            }
        }
        if (check) {
            for (auto i: ans) cout << i;
            cout << "\n";
        }
        return;
    }

    for (auto i: arr) {
        if (!ans.empty() && ans.back() > i) continue;
        visit[i - 'a'] = true;
        ans.push_back(i);
        recursive(n + 1);
        ans.pop_back();
        visit[i - 'a'] = false;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    char t;
    cin >> R >> C;

    for (int i = 0; i < C; ++i) {
        cin >> t;
        arr.push_back(t);
    }

    sort(arr.begin(), arr.end());

    recursive(0);

    return 0;
}