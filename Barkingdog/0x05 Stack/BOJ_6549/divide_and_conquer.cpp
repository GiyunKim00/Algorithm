#include <iostream>

using namespace std;
/**
 * 분할정복 합 계산 알고리즘. 수가 커져도 연산 속도 우월
 * @param x
 * @return 1 ... X까지의 합
 */
long long int divide_and_conquer_sum(int x) {
    if (x == 1) return 1;
    else {
        if (x % 2 == 0) return divide_and_conquer_sum(x / 2) * 2 + (x / 2) * (x / 2);
        else return divide_and_conquer_sum((x - 1) / 2) * 2 + ((x - 1) / 2) * ((x - 1) / 2) + x;
    }
}

/**
 * 재귀방식의 합 계산 알고리즘. 수가 커지면 Stack Overflow 발생
 * @param x
 * @return 1 ... X까지의 합
 */
long long int recursive_sum(int x) {
    if(x == 1) return 1;
    else return x + recursive_sum(x-1);
}

int main() {
    int N = 5000000;
    cout << divide_and_conquer_sum(N) << "\n";
//    cout << recursive_sum(N);
    return 0;
}
/**
 * [분할 정복]
 * 주어진 문제를 둘 이상의 부분문제로 나눈 뒤 각 문제에 대한 답을 계산하고, 이를 병합해 문제를 해결하는 알고리즘
 * 분할정복에는 대표젹으로 수열의 합과 병합 정렬이 존재.
 * 1 ~ 8까지의 합을 구한다고 가정하자.
 * 1 + 2 + 3 + 4 + 5 + 6 + 7 + 8 <= 일반 재귀합으로 구할 경우 N이 커지면 stack overflow가 발생함.
 * 이걸 분할 정복으로 구한다면?
 * 1 + 2 + 3 + 4 + 5 + 6 + 7 + 8 => (1 + 2 + 3 + 4) + (1 + 4 + 2 + 4 + 3 + 4 + 4 + 4)로 구성할 수 있다.
 * => (1 + 2 + 3 + 4) + 4 * 4 + (1 + 2 + 3 + 4) => 2 * (1 + 2 + 3 + 4) + 4 * 4
 * 이걸 일반화하면 2 * (1 + ... + N/2) + (N/2)^2.
 * 1 + ... + N/2을 다시 분할하면 1 + ... +N/4로, N/8로 계속 분할할 수 있음.
 * 위 식은 짝수에서만 동작하며, 홀수에서는 1 + ... + N-1 까지의 합을 구한 뒤 N을 따로 더해준다.
*/