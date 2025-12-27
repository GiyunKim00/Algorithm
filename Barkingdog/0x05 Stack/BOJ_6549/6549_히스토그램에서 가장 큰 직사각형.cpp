#include <iostream>
#include <stack>

using namespace std;

int main() {
    while (true) {
        long long N, max = 0, check = 0, low = 1000000000;
        bool zero = false;
        stack<pair<long long, long long>> s;
        cin >> N;
        if (!N) break;
        pair<long long, long long> low_idx = {0, 0};

        for (int i = 0; i < N; ++i) {
            int t;
            cin >> t;
            if(t == 0) {
                check = i;
                zero = true;
            }
            else if (low > t) low = t;
//            cout << "now in : " << t << "\n";
            max = (max > t) ? max : t;

            if (s.empty()) {
                low_idx = {t, i};
                s.emplace(t, i);
//                cout << "High : " << s.top().first << ", idx : " << s.top().second << ", max : " << max << "\n";
            } else {
                if (s.top().first < t) {
                    s.emplace(t, i);
                    if(i - check != 1) max = (max > low * (i - check + 1)) ? max : low * (i - check + 1);
                    else max = (max > low * (i - check)) ? max : low * (i - check);
//                    cout << "High : " << s.top().first << ", idx : " << s.top().second << ", max : " << max << "\n";
                } else if(s.top().first == t) {
                    s.emplace(t, i);
                    max = (max > low_idx.first * (i - low_idx.second + 1))?max : low_idx.first * (i - low_idx.second + 1);
                }
                else {
//                    cout << "High : " << s.top().first << ", idx : " << s.top().second << ", max : " << max << "\n";
                    if(check == 0) max = (max > low * (i - check + 1)) ? max : low * (i - check + 1);
                    else max = (max > low * (i - check)) ? max : low * (i - check);
                    long long int max_high_idx = s.top().second;
                    while (!s.empty() && s.top().first > t) {
                        s.pop();
                        if(!s.empty()) {
                            max = (max >= (s.top().first * (max_high_idx - s.top().second + 1))) ? max : s.top().first * (max_high_idx - s.top().second + 1);
//                            cout << "from : " << s.top().second << ", to : " << max_high_idx << "\n";
                            if(t <= s.top().first) max = (max >= t * (i - s.top().second + 1)) ? max : t * (i - s.top().second + 1);
                            if(s.top().first == 0) max = (max >= t * (i - s.top().second)) ? max : t * (i - s.top().second);
                        } else {
//                            cout <<" hello\n";
                            max = (max >= t * (i - max_high_idx + 1)) ? max : t * (i - max_high_idx + 1);
                        }
//                        cout << max << "\n";
                    }
                    if (!s.empty()){
                        max = (max >= s.top().first * (i - s.top().second + 1)) ? max : s.top().first * (i - s.top().second + 1);
                        max = (max >= t * (i - s.top().second)) ? max : t * (i - s.top().second);
                    }
                    s.emplace(t, i);
                    low_idx = {t, i};
//                    cout << "High : " << s.top().first << ", idx : " << s.top().second << ", max : " << max << "\n";
                }
            }
        }
        if(!s.empty()) {
            long long int max_high_idx = s.top().second;
            long long int same_idx = 0;
            while(!s.empty()) {
                long long int same = s.top().first;
                s.pop();
                if(!s.empty()) {
                    if(s.top().first == same) same_idx++;
                    max = (max > s.top().first * (max_high_idx - s.top().second + 1))? max : s.top().first * (max_high_idx - s.top().second + 1);
//                    cout << max << " " << max_high_idx << " ~ " << s.top().second + 1 << "\n";
                    if(same_idx) max = (max > same * (max_high_idx - s.top().second))? max : same * (max_high_idx - s.top().second);
//                    cout << max << "\n";
                }
            }
            if(low != 1000000000) {
//                cout << low << " " << (max_high_idx - check) << "\n";
                if(max_high_idx - check != 1 && (check == 0 && !zero)) max = (max > low * (max_high_idx - check + 1))? max : low * (max_high_idx - check + 1);
                else max = (max > low * (max_high_idx - check))? max : low * (max_high_idx - check);
            }
        }
        cout << max << "\n";

    }
    return 0;
}