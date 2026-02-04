#include <iostream>
#include <map>
#include <set>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, num, level;
    cin >> n;

    map<int, set<int>> level_map;
    map<int, int> problem_map;

    while (n--){
        cin >> num >> level;
        level_map[level].insert(num);
        problem_map[num] = level;
    }

    cin >> m;

    while (m--){
        string inst;
        cin >> inst;
        if (inst == "add"){
            cin >> num >> level;
            level_map[level].insert(num);
            problem_map[num] = level;
        }
        else if (inst == "solved"){
            cin >> num;
            int k = problem_map[num];
            level_map[k].erase(num);
            if (level_map[k].empty()) level_map.erase(k);
            problem_map.erase(num);
        }
        else{
            cin >> level;
            if (level == 1) cout << *level_map.rbegin()->second.rbegin() << "\n";
            else cout << *level_map.begin()->second.begin() << "\n";
        }
    }

    return 0;
}