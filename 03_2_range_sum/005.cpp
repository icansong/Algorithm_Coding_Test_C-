// 나머지 합 구하기
#include <iostream>
using namespace std;

// 내가 직접 작성한 코드 => 시간 복잡도 O(N^2)
/*
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    int S[107] = {0};

    for (int i = 1; i <= N; i++) {
        int temp;
        cin >> temp;

        S[i] = S[i-1] + temp;
    }
    
    int answer = 0;
    for (int i = 1; i <= N; i++) {
        for (int j = i; j <= N ; j++) {
            int k = S[j] - S[i-1];
            if (k % M == 0)
            answer = answer + 1;
        }
    }

    cout << answer << endl;
}
*/


// 책 코드 => 시간 복잡도 O(N)
#include <vector>
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N,M;
    cin >> N >> M;
    vector<long> S(N,0);
    vector<long> C(M,0);
    long answer = 0;
    cin >> S[0];

    for (int i = 1; i < N; i++) {
        int temp = 0;
        cin >> temp;
        S[i] = S[i-1] + temp;
    }
    
    for (int i = 0; i < N; i++) {
        int remainder = S[i] % M;
        if(remainder == 0) {
            answer++;
        }
        C[remainder]++;
    }

    for (int i = 0; i < M; i++) {
        if (C[i] > 1) {
            answer = answer + (C[i] * (C[i] -1) /2);
        }
    }

    cout << answer << "\n";
}