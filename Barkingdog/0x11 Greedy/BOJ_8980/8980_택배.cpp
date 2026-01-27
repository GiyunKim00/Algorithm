#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct delivery {
    int start;
    int end;
    int amount;
};

bool compare(const delivery &a, const delivery &b) {
    if (a.end == b.end) return a.start < b.start;
    return a.end < b.end;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, c, m, sum = 0, capa, weight;
    cin >> n >> c >> m;
    vector<int> load(n, 0);
    vector<delivery> package(m);

    for (int i = 0; i < m; ++i) cin >> package[i].start >> package[i].end >> package[i].amount;

    sort(package.begin(), package.end(), compare);

    for (auto i: package) {
        capa = c;
        for (int j = i.start; j < i.end; ++j) capa = min(capa, c - load[j]);
        weight = (i.amount >= capa) ? capa : i.amount;

        if (capa) {
            for (int j = i.start; j < i.end; ++j) load[j] += weight;
            sum += weight;
        }
    }

    cout << sum;

    return 0;
}