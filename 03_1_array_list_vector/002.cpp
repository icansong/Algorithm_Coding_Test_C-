// 평균 구하기

#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;

    int score[1000];
    for(int i = 0; i < N; i++) {
        cin >> score[i];
    }

    int max = 0;
    int sum = 0;
    for(int i = 0; i < N; i++) {
        if (score[i] > max) {
            max = score[i];
        }
        sum = sum + score[i];
    }

    double answer;
    answer = sum * 100 / max / N;
    cout << answer;
}