// 제곱이 아닌 수 찾기
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int max, min;
    cin >> min >> max;

    vector<int> A(max+1,1);
    for (int i = 0; i < min; i++) {
        A[i] = 0;
    }

    for (int i = 2; i <= sqrt(max); i++) {
        int temp = i * i;
        for (int j = min; j <= max; j++) {
            if (j % temp == 0) {
                A[j] = 0;
            }
        }
    }

    int answer = 0;
    for (int i = min; i <= max; i++) {
        answer = answer + A[i];
    }
    cout << answer;
}