#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, ans = 0;
    map<int, int> team;
    cin >> n;
    vector<pair<int, int>> student(n);
    for (int i = 0; i < n; ++i) cin >> student[i].first >> student[i].second;
    sort(student.begin(), student.end(), greater<>());

    for (auto [height, limit] : student){
        auto target = team.lower_bound(limit);
        if (target == team.begin()){
            team[1]++;
            ans++;
        }
        else{
            --target;
            int current_size = target->first;
            if (--(target->second) == 0) team.erase(target);
            team[current_size + 1]++;
        }
    }
    cout << ans;
    return 0;
}