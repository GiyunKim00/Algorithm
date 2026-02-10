#include <iostream>

using namespace std;

char l[26], r[26];

void preorder(const char c) {
    cout << c;
    const int nxt = c - 'A';
    if (l[nxt]) preorder(l[nxt]);
    if (r[nxt]) preorder(r[nxt]);
}

void inorder(const char c) {
    const int nxt = c - 'A';
    if (l[nxt]) inorder(l[nxt]);
    cout << c;
    if (r[nxt]) inorder(r[nxt]);
}

void postorder(const char c) {
    const int nxt = c - 'A';
    if (l[nxt]) postorder(l[nxt]);
    if (r[nxt]) postorder(r[nxt]);
    cout << c;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    while (n--){
        char a, b, c;
        cin >> a >> b >> c;
        if (b != '.') l[a - 'A'] = b;
        if (c != '.') r[a - 'A'] = c;
    }

    preorder('A');
    cout << "\n";
    inorder('A');
    cout << "\n";
    postorder('A');

    return 0;
}