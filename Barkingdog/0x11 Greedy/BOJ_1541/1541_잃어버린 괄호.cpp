#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tmp = 0;
    int sum = 0;
    bool negative = false;
    string s, t;
    cin >> s;

    for(auto i : s) {
        if(isdigit(i)) t += i;
        else {
            tmp = stoi(t);
            t="";
            if(negative)sum -= tmp;
            else sum += tmp;
            if(i == '-') negative = true;
        }
    }

    if(negative) sum -= stoi(t);
    else sum += stoi(t);

    cout << sum;

    return 0;
}