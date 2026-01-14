#include <iostream>
#include <vector>

using namespace std;
int N, M;
int visit[10];
vector<int> ans;

void back_tracking(int size) {
    if (size == M) {
        for (auto i: ans) cout << i << " ";
        cout << "\n";
        return;
    }

    for (int i = 1; i <= N; ++i) {
        if (visit[i]) continue;
        visit[i] = true;
        ans.push_back(i);
        back_tracking(size + 1);
        ans.pop_back();
        visit[i] = false;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> M;
    back_tracking(0);
    return 0;
}