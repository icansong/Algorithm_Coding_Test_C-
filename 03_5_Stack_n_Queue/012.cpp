// 오큰수 구하기
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    vector<int> A(N,0);
    stack<int> B;
    vector<int> Result(N,-1);

    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    B.push(0);
    for (int i = 1; i < N; i++) {
        int k = B.top();
        if (A[k] < A[i]) {
            while (!B.empty() && A[B.top()] < A[i]) {
                Result[B.top()] = A[i];
                B.pop();
            }
            B.push(i);
        }
        else {
            B.push(i);
        }
    }

    for (int i = 0; i < N; i++) {
        cout << Result[i] << " ";
    }
}