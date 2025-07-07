#include <iostream>
#include <stack>
#include <vector>
using namespace std;
/*
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    vector<int> A(N,0);
    vector<char> Result;

    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    stack<int> numbers;
    numbers.push(1);

    bool result = true;

    for (int i = 0; i < N; i++) {
        int now = A[i];
        if (numbers.top() <= now) {
            while (numbers.top() <= now) {
                int temp = numbers.top();
                numbers.push(temp + 1);
                Result.push_back('+');
            }
            numbers.pop();
            Result.push_back('-');
        }
        else if (numbers.top() > now) {
            int n = numbers.top();
            if (n > now) {
                cout << "NO" << "\n";
                result = false;
                break;
            }
            numbers.pop();
            Result.push_back('-');
        }
    }
    
    if (result) {
        for (int i = 0; i < Result.size(); i++) {
            cout << Result[i] << "\n";
        }
    }
}
*/

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    vector<int> A(N,0);
    vector<char> Result;

    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    stack<int> numbers;
    int num = 1;

    bool result = true;

    for (int i = 0; i < N; i++) {
        int now = A[i];
        if (num <= now) {
            while (num <= now) {
                numbers.push(num++);
                Result.push_back('+');
            }
            numbers.pop();
            Result.push_back('-');
        }
        else if (num > now) {
            int n = numbers.top();
            if (n > now) {
                cout << "NO" << "\n";
                result = false;
                break;
            }
            numbers.pop();
            Result.push_back('-');
        }
    }
    
    if (result) {
        for (int i = 0; i < Result.size(); i++) {
            cout << Result[i] << "\n";
        }
    }
}