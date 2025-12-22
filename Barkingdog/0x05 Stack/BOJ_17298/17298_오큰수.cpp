#include <iostream>
#include <stack>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int N;
  stack<int> s1, s2, ans;

  cin >> N;

  for (int i = 0; i < N; ++i) {
    int k;
    cin >> k;
    s1.push(k);
  }

  s2.push(s1.top());
  s1.pop();
  ans.push(-1);

  for (int i = 1; i < N; ++i) {
    if (s2.top() > s1.top()) {
      ans.push(s2.top());
    } else {
      while (!s2.empty() && s2.top() <= s1.top()) {
        s2.pop();
      }
      if (s2.empty()) ans.push(-1);
      else ans.push(s2.top());
    }
    s2.push(s1.top());
    s1.pop();
  }

  while (!ans.empty()) {
    cout << ans.top() << " ";
    ans.pop();
  }

  return 0;
}