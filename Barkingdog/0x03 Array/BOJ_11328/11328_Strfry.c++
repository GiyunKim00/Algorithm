//
// Created by KimGiyun on 25. 11. 15.
//

#include <iostream>

using namespace std;

int main() {
  int n = 0;
  cin >> n;
  while (n--) {
    string a, b;
    int arr[26] = {0,};
    bool check = true;
    cin >> a >> b;

    if (a.length() != b.length()) {
      cout << "Impossible\n";
      continue;
    }

    for (int i = 0; i < a.length(); ++i) {
      arr[a[i] - 'a']++;
      arr[b[i] - 'a']--;
    }

    for (auto i: arr) {
      if (i != 0) {
        check = false;
        break;
      }
    }

    if (check) cout << "Possible\n"; else cout << "Impossible\n";
  }
  return 0;
}
