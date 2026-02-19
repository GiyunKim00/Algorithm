#include <iostream>
#include <unordered_set>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string arr[] = {"c=", "c-", "dz=", "d-", "lj", "nj", "s=", "z="};
    string s;
    cin >> s;
    int ans = 0, pos = 0;
    const int len = static_cast<int>(s.size());

    while (pos < len) {
        if (pos + 2 < len && s.substr(pos, 3) == "dz="){
            ans++;
            pos += 3;
        } else if (pos + 1< len){
            if (string tmp = s.substr(pos, 2); tmp == "c=" || tmp == "c-" || tmp == "d-" || tmp == "lj" || tmp == "nj" || tmp == "s=" || tmp == "z="){
                ans++;
                pos += 2;
            } else{
                ans++;
                pos++;
            }
        } else{
            ans++;
            pos++;
        }
    }

    cout << ans;

    return 0;
}