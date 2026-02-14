#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<int> > arr(n + 1, vector<int>(n + 1, 1e9));
    int nxt[n + 1][n + 1];

    while (m--) {
        int a, b, cost;
        cin >> a >> b >> cost;
        arr[a][b] = min(arr[a][b], cost);
        nxt[a][b] = b;
    }

    for (int i = 1; i <= n; ++i) arr[i][i] = 0;

    for (int k = 1; k <= n; ++k) {
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (arr[i][j] > arr[i][k] + arr[k][j]) {
                    arr[i][j] = arr[i][k] + arr[k][j];
                    nxt[i][j] = nxt[i][k];
                }
            }
        }
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (arr[i][j] == 1e9) cout << "0 ";
            else cout << arr[i][j] << " ";
        }
        cout << "\n";
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (arr[i][j] == 0 || arr[i][j] == 1e9) {
                cout << "0\n";
                continue;
            }
            vector<int> path;
            int a = i;
            while (a != j) {
                path.push_back(a);
                a = nxt[a][j];
            }
            path.push_back(j);
            cout << path.size() << " ";
            for (const auto t: path) cout << t << " ";
            cout << "\n";
        }
    }

    return 0;
}