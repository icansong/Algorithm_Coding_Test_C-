// 버블 정렬 프로그램 1
/* 
내부 for문이 몇 번 수행됐는지 구하는 아이디어!!
swap은 한 번에 1만큼만 이동 가능 
=> 따라서 정렬 후 index와 원래 index를 비교해 왼쪽으로 가장 많이 이동한 값에 1을 더한 (swap이 일어나지 않은 반복문 한 번 더 시행) 값이 답
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    vector<pair<int,int>> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i].first;
        A[i].second = i;
    }

    // pair 값이 원소인 벡터에서 sort는 first 값을 기준으로 정렬, first 값이 같을 경우 second 값을 비교해 정렬
    sort(A.begin(), A.end());
    
    int M = 0;
    for (int i = 0; i < N; i++) {
        int k = A[i].second - i;
        if (k >  M) {
            M = k;
        }
    }

    cout << M + 1;
}