#include <iostream>
#include <queue>
#include <climits>

using namespace std;

int x = 1, max_depth = 1;
int l[10001], r[10001], root[10001];
vector<int> minX(10001, INT_MAX);
vector<int> maxX(10001, 0);

void inorder(const int idx, const int depth) {
    if (l[idx]) inorder(l[idx], depth + 1);
    minX[depth] = min(x, minX[depth]);
    maxX[depth] = max(x++, maxX[depth]);
    max_depth = max(depth, max_depth);
    if (r[idx]) inorder(r[idx], depth + 1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int a, b, c;
        cin >> a >> b >> c;

        if (b != -1) {
            l[a] = b;
            root[b] = true;
        }
        if (c != -1) {
            r[a] = c;
            root[c] = true;
        }
    }

    int root_node;
    for (int i = 1; i <= n; ++i) {
        if (!root[i]) {
            root_node = i;
            break;
        }
    }

    inorder(root_node, 1);

    int ans_level = 1;
    int ans_width = maxX[1] - minX[1] + 1;

    for (int i = 2; i <= max_depth; ++i) {
        int width = maxX[i] - minX[i] + 1;
        if (width > ans_width) {
            ans_width = width;
            ans_level = i;
        }
    }

    cout << ans_level << " " << ans_width;

    return 0;
}