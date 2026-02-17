#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<vector<int>> arr(n + 1, vector<int>(n + 1, 1e9)), path(n + 1, vector<int>(n + 1));

    while (m--){
        int a, b, cost;
        cin >> a >> b >> cost;
        arr[a][b] = min(arr[a][b], cost);
        path[a][b] = b;
        arr[b][a] = min(arr[b][a], cost);
        path[b][a] = a;
    }

    for (int i = 1; i <= n; ++i) arr[i][i] = 0;

    for (int k = 1; k <= n; ++k)
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j){
                if (arr[i][j] > arr[i][k] + arr[k][j]){
                    arr[i][j] = arr[i][k] + arr[k][j];
                    path[i][j] = path[i][k];
                }
            }

    for (int i = 1; i <= n; ++i){
        for (int j = 1; j <= n; ++j){
            if (i == j) cout << "- ";
            else cout << path[i][j] << " ";
        }
        cout << "\n";
    }


    return 0;
}