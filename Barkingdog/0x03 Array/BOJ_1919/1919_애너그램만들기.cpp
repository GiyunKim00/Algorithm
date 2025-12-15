//
// Created by KimGiyun on 25. 9. 24.
//

#include <iostream>

using namespace std;

/**
 * @brief first code
 * 두 번째 식에서, 로직 상 오류가 있었음. 이전 배열에서, 이후 업데이트 되는 값을 뺀다고만 생각했는데... 배열은 하나이고, 그 배열에 넣는 값도 실시간으로 체크한다는 걸 간과함.
 */
void first_code() {
  string str;
  int arr[26] = {0,};
  int cnt = 0;

  cin >> str;
  for (char c: str) arr[c - 'a']++;

  for (auto i: arr)
    cout << i << " ";
  cout << "\n";

  cin >> str;

  for (char c: str) {
    int n = c - 'a';
    if (arr[n] > 0) arr[n]--;
    else arr[n]++;
  }

  for (auto i: arr)
    cout << i << " ";
  cout << "\n";

  for (auto i: arr)
    cnt += i;

  cout << cnt;
}

/**
 * @brief second code
 * 최적화 완료
 * 배열을 재활용하되, 첫 입력 시 ++로, 다음 입력 시 --로 통일함. 이로써 abc, xyz와 같은 입력도 6으로 정상출력할 수 있게 되었음.
 */
void second_code() {
  string str;
  int arr[26] = {0,};
  int cnt = 0;

  cin >> str;
  for (char c: str) arr[c - 'a']++;

  cin >> str;
  for (char c: str) arr[c - 'a']--;

  for (auto i: arr)cnt += abs(i);

  cout << cnt;
}

int main() {
//  first_code();
  second_code();
  return 0;
}

