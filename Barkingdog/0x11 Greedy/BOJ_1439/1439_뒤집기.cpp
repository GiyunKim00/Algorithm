#include <iostream>

using namespace std;

int arr[2];

int main() {
    string s;
    char last_word;
    cin >> s;
    last_word = s[0];
    arr[last_word - '0']++;

    for (auto c : s){
        if (c != last_word)arr[c - '0']++;
        last_word = c;
    }

    cout << min(arr[0], arr[1]);
    return 0;
}
