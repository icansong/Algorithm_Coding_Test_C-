#include <iostream>
#include <cstdlib>
#include <climits>

using namespace std;
// 구간 합 관련 코드
int main ()
{
    int testcase;
    cin >> testcase;

    int answer = 0;                             // 오류4: 자료형 범위 오류 찾아보기 (int -> long 으로) (int의 범위 < long의 범위 < long long)
    int A[100001] = {0};

    for (int i = 1; i < 10001; i++) {           // 오류2: 반복문에서 인덱스 범위 (i<10001 -> i<100001 로 바꿔야함, A배열의 크기)
        A[i] = rand() * 100;    
    }

    for (int t = 1; t < testcase + 1; t++) {    // 오류1: 변수 초기화 (answer을 t마다 초기화해야함)
        int start, end;
        cin >> start >> end ;
        for (int i = start; i <= end; i++) {
            answer += A[i];
        }
        cout << testcase << " " << answer;      // 오류3: 잘못된 변수 사용 오류 (testcase -> t 로 바꿔야함)
    }
}