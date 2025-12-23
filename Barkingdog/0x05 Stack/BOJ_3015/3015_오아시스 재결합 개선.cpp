#include <iostream>
#include <stack>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  long long int ans = 0;
  int N;
  stack<pair<int, int>> s;

  cin >> N;

  for (int i = 0; i < N; ++i) {
    int k, same = 1;
    cin >> k;

    if (s.empty()) s.emplace(k, 1);
    else {
      while (!s.empty() && k > s.top().first) {
        ans += s.top().second;
        s.pop();
      }
      if (!s.empty()) {
        if (k == s.top().first) {
          same += s.top().second;
          ans += s.top().second;
          s.pop();
          if (!s.empty()) ans++;
        } else ans++;
      }

      s.emplace(k, same);
    }
  }

  cout << ans;

  return 0;
}