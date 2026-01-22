#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct card {
    int idx;
    int money;
    float value;
};

bool compare(card &a, card &b) {
    return a.value > b.value;
}

int main() {
    int n, idx = 0, total_spent = 0, total_cards = 0;
    cin >> n;
    vector<card> arr(n);

    for (int i = 0; i < n; ++i) {
        cin >> arr[i].money;
        arr[i].idx = i + 1;
        arr[i].value = float(arr[i].money) / (i + 1);
    }
    sort(arr.begin(), arr.end(), compare);

    while (idx < n) {
        if ((n - total_cards) / arr[idx].idx >= 1) {
            total_spent += arr[idx].money * ((n-total_cards) / arr[idx].idx);
            total_cards += ((n-total_cards) / arr[idx].idx) * arr[idx].idx;
        }
        idx++;
    }

    cout << total_spent;

    return 0;
}