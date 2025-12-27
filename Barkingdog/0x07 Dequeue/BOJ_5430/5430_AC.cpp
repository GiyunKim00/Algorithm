#include <iostream>
#include <deque>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin >> T;

    while (T--) {
        string p;
        int n, tmp = 0;
        bool read_dir = true, digit_check = false, error = false;
        deque<int> q;
        cin >> p >> n;
        string x;
        cin >> x;

        for (auto i: x) {
            if (digit_check) {
                if (isdigit(i)) {
                    tmp *= 10;
                    tmp += i - '0';
                } else {
                    digit_check = false;
                    q.push_back(tmp);
                    tmp = 0;
                }
            } else {
                if (isdigit(i)) {
                    tmp += i - '0';
                    digit_check = true;
                }
            }
        }

        for (auto c: p) {
            if (c == 'R') read_dir = !read_dir;
            else if (c == 'D' && !q.empty()) {
                if (read_dir) q.pop_front();
                else q.pop_back();
            } else {
                cout << "error\n";
                error = true;
                break;
            }
        }

        if (error) continue;

        if (q.empty()) cout << "[]\n";
        else {
            cout << "[";
            if (read_dir) {
                while (true) {
                    cout << q.front();
                    q.pop_front();
                    if (!q.empty()) cout << ",";
                    else break;
                }
            } else {
                while (true) {
                    cout << q.back();
                    q.pop_back();
                    if (!q.empty()) cout << ",";
                    else break;
                }
            }
            cout << "]\n";
        }
    }

    return 0;
}