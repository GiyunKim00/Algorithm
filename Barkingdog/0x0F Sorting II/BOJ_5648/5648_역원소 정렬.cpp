#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int N;
    string s;
    cin >> N;
    vector<long long int> v;
    while (N--) {
        cin >> s;
        reverse(s.begin(), s.end());
        v.push_back(stoll(s));
    }
    sort(v.begin(), v.end());
    for (auto i: v) cout << i << "\n";

    return 0;
}