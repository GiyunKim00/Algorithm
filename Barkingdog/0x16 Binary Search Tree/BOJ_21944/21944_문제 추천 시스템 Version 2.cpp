#include <iostream>
#include <set>
#include <map>
#include <unordered_map>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, problem, level, group;
    unordered_map<int, pair<int, int>> problem_level;
    map<int, set<int>> all_problem;
    map<int, set<pair<int, int>>> group_problem;
    cin >> n;
    while (n--){
        cin >> problem >> level >> group;
        problem_level[problem] = {level, group};
        all_problem[level].insert(problem);
        group_problem[group].emplace(level, problem);
    }

    cin >> n;
    while (n--){
        string inst;
        cin >> inst;

        if (inst == "add"){
            cin >> problem >> level >> group;
            problem_level[problem] = {level, group};
            all_problem[level].insert(problem);
            group_problem[group].emplace(level, problem);
        }
        else if (inst == "solved"){
            cin >> problem;
            level = problem_level[problem].first;
            group = problem_level[problem].second;

            all_problem[level].erase(problem);
            if (all_problem[level].empty()) all_problem.erase(level);

            group_problem[group].erase({level, problem});
            if (group_problem[group].empty()) group_problem.erase(group);

            problem_level.erase(problem);
        }
        else if (inst == "recommend"){
            cin >> group >> level;
            if (level == 1) cout << group_problem[group].rbegin()->second << "\n";
            else cout << group_problem[group].begin()->second << "\n";
        }
        else if (inst == "recommend2"){
            cin >> level;
            if (level == 1) cout << *all_problem.rbegin()->second.rbegin() << "\n";
            else cout << *all_problem.begin()->second.begin() << "\n";
        }
        else{
            int mode;
            cin >> mode >> level;
            if (mode == 1){
                if (all_problem.lower_bound(level) == all_problem.end()) cout << "-1\n";
                else cout << *all_problem.lower_bound(level)->second.begin() << "\n";
            }
            else{
                auto it = all_problem.lower_bound(level);
                if (it == all_problem.begin()) cout << "-1\n";
                else cout << *prev(it)->second.rbegin() << "\n";
            }
        }
    }
    return 0;
}