// 숫자의 합 구하기

#include <iostream>
using namespace std;

int main() {
    int N;
    string numbers;

    cin >> N;
    cin >> numbers;

    int sum = 0;
    for(int i = 0; i < N; i++) {
        sum += numbers[i] -'0';
    }
    cout << sum << "\n";
}