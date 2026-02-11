#include <iostream>
using namespace std;
int n, lst_num;
int l[100001], r[100001], p[100001];
bool visit[100001];

void inorder(const int idx) {
    if (l[idx]) inorder(l[idx]);
    lst_num = idx;
    if (r[idx]) inorder(r[idx]);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int idx = 1, cnt = 0;

    cin >> n;

    while (n--) {
        int a, b, c;

        cin >> a >> b >> c;

        if (b != -1) {
            l[a] = b;
            p[b] = a;
        }
        if (c != -1) {
            r[a] = c;
            p[c] = a;
        }
    }

    inorder(idx);

    while (true) {
        visit[idx] = true;
        if (l[idx] && !visit[l[idx]]) {
            idx = l[idx];
            cnt++;
        } else if (r[idx] && !visit[r[idx]]) {
            idx = r[idx];
            cnt++;
        } else {
            if (idx == lst_num) break;
            idx = p[idx];
            cnt++;
        }
    }

    cout << cnt;

    return 0;
}