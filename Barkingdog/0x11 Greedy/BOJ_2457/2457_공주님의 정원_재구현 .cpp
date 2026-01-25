#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int date[13] = {
        0,
        31, 28, 31, 30, 31, 30,
        31, 31, 30, 31, 30, 31
};

struct flower {
    int start_month;
    int start_day;
    int end_month;
    int end_day;
    int total_date;

    int compute_date() {
        int start_sum = 0, end_sum = 0;
        for (int i = 1; i < start_month; ++i)
            start_sum += date[i];
        start_sum += start_day;

        for (int i = 1; i < end_month; ++i)
            end_sum += date[i];
        end_sum += end_day;

        return end_sum - start_sum;
    }
};

bool compare(flower &a, flower &b) {
    if (a.start_month == b.start_month) {
        if (a.start_day == b.start_day) return a.total_date < b.total_date;
        return a.start_day < b.start_day;
    }
    return a.start_month < b.start_month;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, idx = 0, cnt = 0;
    int start_month = 3, start_day = 1, cur_month = 0, cur_day = 0, end_month = 11;

    cin >> n;

    vector<flower> arr(n);

    for (int i = 0; i < n; ++i) {
        cin >> arr[i].start_month >> arr[i].start_day >> arr[i].end_month >> arr[i].end_day;
        arr[i].total_date = arr[i].compute_date();
    }

    sort(arr.begin(), arr.end(), compare);

    while (start_month <= end_month) {
        bool found = false;

        while (idx < n && ((arr[idx].start_month == start_month && arr[idx].start_day <= start_day) ||
               (arr[idx].start_month < start_month))) {
            found = true;
            if ((arr[idx].end_month == cur_month && arr[idx].end_day > cur_day) ||
                (arr[idx].end_month > cur_month)) {
                cur_month = arr[idx].end_month;
                cur_day = arr[idx].end_day;
            }
            idx++;
        }

        if (!found) {
            cout << 0;
            return 0;
        }

        cnt++;
        start_month = cur_month;
        start_day = cur_day;
    }

    cout << cnt;

    return 0;
}