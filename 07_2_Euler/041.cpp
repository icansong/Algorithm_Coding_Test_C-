// 오일러 피 함수 구현하기
#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N;
    cin >> N;

    vector<int> A(N+1,0);
    for (int i = 0; i <= N; i++) {
        A[i] = i;
    }

    for (int i = 2; i <= N; i++) {
        if (A[i] == i) {
            for (int j = i; j <= N; j = j + i) {
                A[j] = A[j] - A[j] / i;
            }
        }
    }

    cout << A[N];
}