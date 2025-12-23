#include <iostream>
#include <stack>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  long long N, cnt = 0;
  int same = 0;
  stack<int> s;
  cin >> N;

  for (int i = 0; i < N; ++i) {
    int k;
    cin >> k;
    cout << "now inserted : " << k << ", s.top : ";
    if (s.empty()) {
      s.push(k);
      cout << "empty\n";
    } else {
      cout << s.top() << "\n";
      while (!s.empty() && k > s.top()) {
        cout << "compare k : " << k << " > " << s.top() << "\n";
        s.pop();
        if(same != 0) {
          cnt += same;
          same = 0;
        }
        cnt++;
      }
      if(!s.empty()) {
        if (k == s.top()) {
          same += 1;
        }
        cnt++;
      }
      s.push(k);
    }
    cout << "ans : " << cnt << "\n";
  }

  cout << cnt;
  return 0;
}