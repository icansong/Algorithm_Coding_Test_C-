// 내림차순으로 자릿수 정렬하기
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string str;
    cin >> str;

    vector<int> A(str.size(),0);
    for (int i = 0; i < str.size(); i++) {
        // str.substr(i,1) 은 문자열을 길이 1만큼 잘라낸다는 것을 의미
        A[i] = stoi(str.substr(i,1));
    }

    /* 내가 작성한 코드 -> 비교마다 A[i]와 A[j]를 swap하므로 불필요한 swap이 많음
    for (int i = 0; i < str.size(); i++) {
        for (int j = i; j < str.size(); j++) {
            int M = A[i];
            if (A[j] > M) {
                int temp = A[i];
                M = A[j];
                A[i] = M;
                A[j] = temp;
            }
        }
    }
    */
    for (int i = 0; i < str.size(); i++) {
        int Max_index = i;
        for (int j = i+1; j < str.size(); j++) {
            if (A[j] > A[Max_index]) {
                Max_index = j;
            }
        }
        int temp = A[i];
        A[i] = A[Max_index];
        A[Max_index] = temp;
    }
    
    for (int i = 0; i < str.size(); i++) {
        cout << A[i];
    }
}