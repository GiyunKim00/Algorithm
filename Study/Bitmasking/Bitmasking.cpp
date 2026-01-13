#include <iostream>
#include <bit>

using namespace std;

int main() {

    /**
     * 자연수 10은 2진수로 변환 시 1010으로, 4자리로 변환됨. 이를 바로 계산해주는 함수임. bit include 필요.
     */
    int bits = __bit_width(10);

    /**
     * 9를 2진수로 변환 시 1001임. 이 때 1001을 XOR 연산으로 각 자리수마다 한 번 씩 flip 하는 코드임.
     * 1001 -> 1000 / 1011 / 1101 / 0001 이렇게 4번이 바뀜.
     */
    for (int i = 0; i < bits; i++) {
        int nx = 9 ^ (1 << i);
    }
}