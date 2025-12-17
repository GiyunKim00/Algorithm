//
// Created by Giyun Kim on 25. 11. 17.
//
#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int N, K, S, Y, sum = 0;
    cin >> N >> K;
    int arr[2][6] = {0,};

    for (int i = 0; i < N; ++i) {
        cin >> S >> Y;
        arr[S][Y - 1]++;
    }



    for (auto & i : arr) {
        for (int j : i) {
            if (j != 0){
                if(j < K) sum += 1;
                else sum += ceil(j / (double)K);
            }
        }
    }

    cout << sum;

    return 0;
}