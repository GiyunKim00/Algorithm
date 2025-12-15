//
// Created by KimGiyun on 25. 11. 15.
//

#include <iostream>

using namespace std;

int main() {
  int arr[26] = {0,};
  char n;
  while (cin >> n) arr[n - 'a']++;

  for (int i: arr) cout << i << " ";
  return 0;
}
