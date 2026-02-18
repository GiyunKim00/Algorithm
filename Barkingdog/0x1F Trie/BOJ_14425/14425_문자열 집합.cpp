#include <iostream>

using namespace std;

int mx = 5000001, root = 1, unused = 2;
bool check[5000001];
int nxt[5000001][26];

void insert(const string& s) {
    int cur = root;
    for (const auto& c : s){
        if (!nxt[cur][c - 'a']) nxt[cur][c - 'a'] = unused++;
        cur = nxt[cur][c - 'a'];
    }
    check[cur] = true;
}

bool find(const string& s) {
    int cur = root;
    for (const auto& c : s){
        if (!nxt[cur][c - 'a']) return false;
        cur = nxt[cur][c - 'a'];
    }

    return check[cur];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, ans = 0;
    cin >> n >> m;

    while (n--){
        string s;
        cin >> s;
        insert(s);
    }

    while (m--){
        string s;
        cin >> s;
        if (find(s)) ans++;
    }

    cout << ans;

    return 0;
}