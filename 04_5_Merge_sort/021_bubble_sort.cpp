// 버블 정렬 프로그램 2
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
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
    }

    int answer = 0;
    for (int i = 1; i < N; i++) {
        for (int j = 1; j <= N - i; j++) {
            if (A[j] > A[j+1]) {
                int tmp = A[j];
                A[j] = A[j+1];
                A[j+1] = tmp;
                answer++;
            }
        }
    }

    cout << answer;
}