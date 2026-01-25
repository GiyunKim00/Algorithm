#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


struct time_table{
    int start_time;
    int end_time;
};

bool compare(time_table &a, time_table  &b) {
    if (a.end_time == b.end_time) return a.start_time < b.start_time;
    return a.end_time < b.end_time;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, max_val, cnt = 1;
    cin >> n;

    vector<time_table> arr(n);

    for (int i = 0; i < n; ++i) cin >> arr[i].start_time >> arr[i].end_time;

    sort(arr.begin(), arr.end(), compare);

    max_val = arr[0].end_time;

    for (int i = 1; i < n; ++i) {
        if (arr[i].start_time < max_val) continue;
        cnt++;
        max_val = arr[i].end_time;
    }

    cout << cnt;
    return 0;
}