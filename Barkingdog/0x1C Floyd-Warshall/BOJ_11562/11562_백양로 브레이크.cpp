#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> arr(n + 1, vector<int>(n + 1, 1e9));

    while (m--){
        int a, b, mode;
        cin >> a >> b >> mode;

        if (mode) arr[b][a] = 0;
        else arr[b][a] = 1;
        arr[a][b] = 0;
    }

    for (int i = 1; i <= n; ++i) arr[i][i] = 0;

    for (int k = 1; k <= n; ++k)
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j)
                arr[i][j] = min(arr[i][j], arr[i][k] + arr[k][j]);

    cin >> m;

    while (m--){
        int a, b;
        cin >> a >> b;
        cout << arr[a][b] << "\n";
    }

    return 0;
}