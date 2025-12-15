/**
 * 2025.11.26
 */
#include <iostream>

using namespace std;

int main() {
  int mul = 1, a = 0;
  int arr[10] = {0,};
  for (int i = 0; i < 3; i++)
    cin >> a, mul *= a;

  while (mul > 0) {
    arr[mul % 10]++;
    mul /= 10;
  }

  for (int i = 0; i < 10; i++) cout << arr[i] << "\n";
  return 0;
}

