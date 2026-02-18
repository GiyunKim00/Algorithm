#include <iostream>
#include <vector>

using namespace std;
int root, unused;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--){
        int n;
        cin >> n;
        vector<vector<int>> arr(n * 10 + 1, vector<int>(10, 0));
        vector<bool> check(n * 10 + 1, false);
        bool ok = true;

        root = 1, unused = 2;
        while (n--){
            string s;
            cin >> s;

            if (!ok) continue;

            int cur = root;
            for (int i = 0; i < s.size(); ++i){
                if (!arr[cur][s[i] - '0']) arr[cur][s[i] - '0'] = unused++;
                cur = arr[cur][s[i] - '0'];

                if (check[cur] && i != static_cast<int>(s.size()) - 1){
                    ok = false;
                    break;
                }
            }
            if (check[cur])ok = false;
            if (!ok) continue;

            for (int j = 0; j < 10; j++) if (arr[cur][j]){
                ok = false;
                break;
            }

            check[cur] = true;
        }
        if (ok) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}