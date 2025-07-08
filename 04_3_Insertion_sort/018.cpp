// ATM 인출 시간 계산하기
#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    vector<int> A(N,0);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    for (int i = 1; i < N; i++) {
        int index = i;
        for (int j = 0; j <= i-1; j++) {
            if (A[i] < A[j]) {
                index = j;
                break;
            }
        }
        if (index != i) {
            int temp = A[i];
            for (int j = i-1; j >= index; j--) {
                A[j+1] = A[j];
            }
            A[index] = temp;
        }
    }

    vector<int> B(N,0);
    B[0] = A[0];
    int answer = B[0];
    for (int i = 1; i < N; i++) {
        B[i] = B[i-1] + A[i];
        answer = answer + B[i];
    }
    cout << answer;    
}