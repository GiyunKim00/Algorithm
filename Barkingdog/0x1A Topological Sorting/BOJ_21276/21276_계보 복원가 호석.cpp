#include <iostream>
#include <queue>
#include <map>
#include <unordered_map>
#include <algorithm>

using namespace std;

int n, m, indegree[1000];
unordered_map<string, int> name;
vector<string> idx(1000);
map<string, vector<string>> children;
vector<int> arr[1000];
vector<string> ans;

void bfs() {
    queue<int> q;
    for (int i = 0; i < n; ++i) {
        if (indegree[i]) continue;
        q.push(i);
        ans.push_back(idx[i]);
    }

    while (!q.empty()) {
        const int t = q.front();
        q.pop();
        children[idx[t]];
        for (const int &i: arr[t]) {
            if (!--indegree[i]) {
                q.push(i);
                children[idx[t]].push_back(idx[i]);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        name[s] = i;
        idx[i] = s;
    }

    cin >> m;

    while (m--) {
        string son, ancestor;
        cin >> son >> ancestor;
        arr[name[ancestor]].push_back(name[son]);
        indegree[name[son]]++;
    }

    bfs();
    sort(ans.begin(), ans.end());
    cout << ans.size() << "\n";
    for (const auto &i: ans) cout << i << " ";
    cout << "\n";
    for (auto [fst, snd]: children) {
        sort(snd.begin(), snd.end());
        cout << fst << " " << snd.size() << " ";
        for (const auto& k: snd) cout << k << " ";
        cout << "\n";
    }

    return 0;
}