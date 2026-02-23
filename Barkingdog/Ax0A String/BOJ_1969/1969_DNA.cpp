#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, ans = 0;
    cin >> n >> m;
    vector<vector<int> > arr(m, vector<int>(4, 0));
    vector<string> str(n);
    char consensus[m];

    for (int k = 0; k < n; ++k) {
        string s;
        cin >> s;
        for (int i = 0; i < m; ++i) {
            if (s[i] == 'A') arr[i][0]++;
            else if (s[i] == 'C') arr[i][1]++;
            else if (s[i] == 'G') arr[i][2]++;
            else arr[i][3]++;
        }
        str[k] = s;
    }

    for (int i = 0; i < m; ++i) {
        int best = 0;
        for (int j = 1; j < 4; j++)
            if (arr[i][j] > arr[i][best]) best = j;
        if (best == 0) consensus[i] = 'A';
        else if (best == 1) consensus[i] = 'C';
        else if (best == 2) consensus[i] = 'G';
        else consensus[i] = 'T';

        for (int j = 0; j<n; ++j) if (str[j][i] != consensus[i]) ans++;
    }

    for (int i = 0; i<m; ++i) cout << consensus[i];
    cout << "\n" << ans;

    return 0;
}