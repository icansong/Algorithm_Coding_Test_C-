// 연속된 자연수의 합 구하기
#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;

    int start_index = 1;
    int end_index = 1;
    int sum = 1;

    int count = 1;

    while (end_index != N) {
        if (sum == N) {
            count++;
            end_index++;
            sum = sum + end_index;
        }
        
        else if (sum > N) {
            sum = sum - start_index;
            start_index++;
        }
        
        else {
            end_index++;
            sum = sum + end_index;
        }
    }

    cout << count << "\n";
}