// 카드 정렬하기
#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
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

    sort(A.begin(),A.end());

    stack<int> myStack;
    for (int i = 0; i < N; i++) {
        myStack.push(A[N-1-i]);
    }

    int answer = 0;
    while (myStack.size() > 1) {
        int a = myStack.top();
        myStack.pop();
        int b = myStack.top();
        myStack.pop();

        myStack.push(a+b);
        answer += a+b;
    }
    cout << answer;
}