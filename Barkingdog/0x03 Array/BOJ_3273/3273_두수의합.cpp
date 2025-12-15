/**
 * 2025.11.26
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  vector<int> vec;
  int n = 0, tmp = 0, cnt = 0, ans = 0;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> tmp;
    vec.push_back(tmp);
  }
  cin >> ans;
  tmp = 0;
  n--;
  sort(vec.begin(), vec.end());
  while (tmp < n) {
    int k = vec[tmp] + vec[n];
    if (k == ans) {
      ++cnt;
      ++tmp;
      --n;
    } else if (k < ans) ++tmp;
    else --n;
  }

  cout << cnt;

  return 0;
}

