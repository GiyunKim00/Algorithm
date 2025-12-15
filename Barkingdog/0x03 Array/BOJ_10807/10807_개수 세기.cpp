//
// Created by KimGiyun on 25. 11. 15.
//

#include <iostream>

using namespace std;

int main() {
  int N = 0, v = 0, cnt = 0;
  int arr[100] = {0,};

  cin >> N;
  for (int i = 0; i < N; ++i) cin >> arr[i];
  cin >> v;

  for (int i = 0; i < N; ++i) {
    if (arr[i] == v) cnt++;
  }

  cout << cnt;

  return 0;
}
