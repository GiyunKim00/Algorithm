#include <iostream>
#include <list>

using namespace std;

int main() {
    int n, a, cnt = 0;
    cin >> n;

    list<int> arr;


    while (n--) {
        int move = 0, from_front = 0, from_end = arr.size() - 1;
        cin >> a;
        if (arr.empty()) arr.push_back(a);
        else {
            if (arr.front() > a) {
                cnt += 1;
                arr.push_front(a);
            }
            else if (arr.back() < a) arr.push_back(a);
            else {
                auto it = arr.begin();
                while (it != arr.end() && *it < a) {
                    ++it;
                    ++from_front;
                }
                it = arr.end();
                --it;

                while (true) {
                    if (*it <= a) break;
                    ++from_end;
                    if (it == arr.begin()) break;
                    --it;
                }

                move = min(from_front, from_end);
                cnt += move;

                it = arr.begin();
                advance(it, from_front);
                arr.insert(it, a);
            }
        }
    }

    cout << cnt;

    return 0;
}