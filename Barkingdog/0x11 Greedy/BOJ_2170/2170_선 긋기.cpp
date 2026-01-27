#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct line {
    int start;
    int end;
};

bool compare(const line &a, const line &b) {
    if (a.start == b.start) return a.end > b.end;
    return a.start < b.start;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, min_val, max_val;
    long long int sum = 0;
    cin >> n;
    vector<line> arr(n);

    for (int i = 0; i < n; ++i) cin >> arr[i].start >> arr[i].end;

    sort(arr.begin(), arr.end(), compare);

    min_val = arr[0].start;
    max_val = arr[0].end;

    for(auto i : arr) {
        if(i.start <= max_val) max_val = max(max_val, i.end);
        else {
            sum += max_val - min_val;
            min_val = i.start;
            max_val = i.end;
        }
    }

    sum += max_val - min_val;

    cout << sum;
    return 0;
}