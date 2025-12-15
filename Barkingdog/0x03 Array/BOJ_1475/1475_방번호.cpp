//
// Created by KimGiyun on 25. 9. 24.
//


#include <iostream>

using namespace std;

/**
 * @brief first code
 * 코드길이 468B, 메모리 2020KB
 */
int first_code() {
  int n = 0, max = 0;
  int arr[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
  cin >> n;

  while (n > 0) {
    arr[n % 10]++;
    n /= 10;
  }

  for (int i = 0; i < 10; ++i) {
    if (i != 6 && i != 9) {
      if (arr[i] > max) max = arr[i];
    }
  }
  int k = (arr[6] + arr[9]) / 2 + (arr[6] + arr[9]) % 2;
  if (max >= k)
    cout << max;
  else cout << k;
}

/**
* @breif second code
 * 최적화 실시
 * O(N)보다 작을 수는 없음. 불필요한 순회를 제거하고, 묶어서 세기로 함.
 * 코드길이 393B, 메모리 2024KB
*/
int second_code() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int arr[10] = {0,};
  int min = 0;
  string n;
  cin >> n;

  for (char c: n) {
    int tmp = c - '0';
    if (tmp == 6 || tmp == 9)
      arr[6]++;
    else min = max(++arr[tmp], min);
  }

  cout << max(min, (arr[6] + 1) / 2);
  return 0;
}

int main() {
  //first_code();
  second_code();
  return 0;
}

