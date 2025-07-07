// DNA 비밀번호
#include <iostream>
using namespace std;

// 내가 작성한 코드. 새로운 함수 선언X => 복잡함
/*
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int DNA_length, pw_length;
    cin >> DNA_length >> pw_length;

    string A;
    cin >> A;

    int checkArr[4];
    for (int i = 0; i < 4; i++) {
        cin >> checkArr[i];
    }

    int myArr[4] = {0};
    for (int i = 0; i < pw_length; i++) {
        if (A[i] == 'A') {
            myArr[0]++;
        }
        else if (A[i] == 'C') {
            myArr[1]++;
        }
        else if (A[i] == 'G') {
            myArr[2]++;
        }
        else if (A[i] == 'T') {
            myArr[3]++;
        }
    }

    int answer = 0;
    if (checkArr[0] <= myArr[0] && checkArr[1] <= myArr[1] && checkArr[2] <= myArr[2] && checkArr[3] <= myArr[3]) {
        answer++;
    }

    for (int i = pw_length; i < DNA_length; i++) {
        int j = i - pw_length;

        if (A[i] == 'A') {
            myArr[0]++;
        }
        else if (A[i] == 'C') {
            myArr[1]++;
        }
        else if (A[i] == 'G') {
            myArr[2]++;
        }
        else if (A[i] == 'T') {
            myArr[3]++;
        }

        if (A[j] == 'A') {
            myArr[0]--;
        }
        else if (A[j] == 'C') {
            myArr[1]--;
        }
        else if (A[j] == 'G') {
            myArr[2]--;
        }
        else if (A[j] == 'T') {
            myArr[3]--;
        }

        if (checkArr[0] <= myArr[0] && checkArr[1] <= myArr[1] && checkArr[2] <= myArr[2] && checkArr[3] <= myArr[3]) {
        answer++;
        }
    }
    cout << answer << "\n";
}
*/

int checkArr[4];
int myArr[4];
int checkSecret = 0;
void Add(char c);
void Remove(char c);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int S, P;
    cin >> S >> P;
    int Result = 0;
    string A;
    cin >> A;

    for (int i = 0; i < 4; i++) {
        cin >> checkArr[i];
        if (checkArr[i] == 0) {
            checkSecret++;
        }
    }
    // 초기 P 부분 문자열 처리
    for (int i = 0; i < P; i++) {
        Add(A[i]);
    }
    if (checkSecret == 4) {
        Result++;
    }
    // 슬라이딩 윈도우 처리 부분
    for (int i = P; i < S; i++) {
        int j = i - P;
        Add(A[i]);
        Remove(A[j]);
        if (checkSecret == 4) {
            Result++;
        }
    }
    cout << Result << "\n";
}

void Add(char c) {
    switch(c) {
    case 'A':
        myArr[0]++;
        if (myArr[0] == checkArr[0]) {
            checkSecret++;
        }
        break;
    case 'C':
        myArr[1]++;
        if (myArr[1] == checkArr[1]) {
            checkSecret++;
        }
        break;
    case 'G':
        myArr[2]++;
        if (myArr[2] == checkArr[2]) {
            checkSecret++;
        }
        break;
    case 'T':
        myArr[3]++;
        if (myArr[3] == checkArr[3]) {
            checkSecret++;
        }
        break;
    }
}

void Remove(char c) {
    switch (c) {
    case 'A':
        if (myArr[0] == checkArr[0]) {
            checkSecret--;
        }
        myArr[0]--;
        break;
    case 'C':
        if (myArr[1] == checkArr[1]) {
            checkSecret--;
        }
        myArr[1]--;
        break;
    case 'G':
        if (myArr[2] == checkArr[2]) {
            checkSecret--;
        }
        myArr[2]--;
        break;
    case 'T':
        if (myArr[3] == checkArr[3]) {
            checkSecret--;
        }
        myArr[3]--;
        break;
    }
}