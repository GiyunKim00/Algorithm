#include <iostream>
#include <set>
#include <map>
#include <unordered_map>

using namespace std;

int problem_level[100001], problem_group[100001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, problem, level, group;
    set<pair<int, int>> global_problem;
    map<int, set<pair<int, int>>> group_problem;
    cin >> n;
    while (n--){
        cin >> problem >> level >> group;
        problem_level[problem] = level;
        problem_group[problem] = group;
        global_problem.emplace(level, problem);
        group_problem[group].emplace(level, problem);
    }

    cin >> n;
    while (n--){
        string inst;
        cin >> inst;

        if (inst == "add"){
            cin >> problem >> level >> group;
            problem_level[problem] = level;
            problem_group[problem] = group;
            global_problem.emplace(level, problem);
            group_problem[group].emplace(level, problem);
        }
        else if (inst == "solved"){
            cin >> problem;
            level = problem_level[problem];
            group = problem_group[problem];

            global_problem.erase({level, problem});
            group_problem[group].erase({level, problem});
            if (group_problem[group].empty()) group_problem.erase(group);
        }
        else if (inst == "recommend"){
            cin >> group >> level;
            if (level == 1) cout << group_problem[group].rbegin()->second << "\n";
            else cout << group_problem[group].begin()->second << "\n";
        }
        else if (inst == "recommend2"){
            cin >> level;
            if (level == 1) cout << global_problem.rbegin()->second << "\n";
            else cout << global_problem.begin()->second << "\n";
        }
        else{
            int mode;
            cin >> mode >> level;
            if (mode == 1){
                if (global_problem.lower_bound({level, -1}) == global_problem.end()) cout << "-1\n";
                else cout << global_problem.lower_bound({level, -1})->second << "\n";
            }
            else{
                auto it = global_problem.lower_bound({level, -1});
                if (it == global_problem.begin()) cout << "-1\n";
                else cout << prev(it)->second << "\n";
            }
        }
    }
    return 0;
}
