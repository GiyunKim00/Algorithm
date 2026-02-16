#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int idx, sum = 0;
    string s;
    cin >> s;

    for (int i = 0; i < 13; ++i){
        int b = (i % 2 == 0) ? 1 : 3;
        if (s[i] == '*') idx = b;
        else{
            int a = s[i] - '0';
            sum += a * b;
        }
    }

    for (int i = 0; i <= 9; ++i){
        if ((idx * i + sum) % 10 == 0){
            cout << i;
            break;
        }
    }

    return 0;
}