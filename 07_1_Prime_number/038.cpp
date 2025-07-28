// 거의 소수 구하기
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int A, B;
    cin >> A >> B;

    vector<int> arr(B+1, 1);
    
    for (int i = 2; i <= sqrt(B); i++) {
        int k = 2;
        while (i * k <= B) {
            arr[i*k] = 0;
            k++;
        }
    }


    int answer = 0;
    for (int i = 2; i <= sqrt(B); i++) {
        if (arr[i] == 1) {
            int temp = i*i;
            while (temp <= B) {
                temp = temp * i;
                answer++;
            }
        }
    }

    cout << answer;
}