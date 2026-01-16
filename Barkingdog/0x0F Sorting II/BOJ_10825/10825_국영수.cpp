#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct score {
    string name;
    int korean;
    int english;
    int math;
};

bool compare(score &a, score &b) {
    if(a.korean != b.korean) return a.korean > b.korean;
    if(a.english != b.english) return a.english < b.english;
    if(a.math != b.math) return a.math > b.math;
    return a.name < b.name;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, korean, english, math;
    string s;
    cin >> n;
    vector<score> ans;
    while (n--) {
        cin >> s >> korean >> english >> math;
        ans.push_back({s, korean, english, math});
    }

    sort(ans.begin(), ans.end(), compare);
    for (auto i: ans) cout << i.name << "\n";
    return 0;
}
