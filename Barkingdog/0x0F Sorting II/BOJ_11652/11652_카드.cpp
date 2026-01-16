#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

bool compare(pair<long long int, int> &a, pair<long long int, int> &b) {
    if(a.second == b.second) return a.first < b.first;
    return a.second > b.second;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    map<long long int, int> m;
    long long int k;

    cin >> N;

    while (N--) {
        cin >> k;
        if (m.find(k) == m.end()) m[k]=1;
        else m[k]++;
    }
    vector<pair<long long int, int>> v(m.begin(), m.end());
    sort(v.begin(), v.end(), compare);

    cout << v[0].first;
}