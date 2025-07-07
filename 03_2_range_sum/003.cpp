// 구간 합 구하기 1

#include <iostream>

using namespace std;

int main() {
    int N, M;
    
    cin >> N >> M;
    
    int S[100000] = {0};

    for(int i = 1; i <= N; i++) {
        int temp;
        cin >> temp;

        S[i] = S[i-1] + temp;
    }

    for(int j = 0; j < M; j++) {
        int start, end;
        cin >> start >> end;

        int answer = S[end] - S[start-1];

        cout << answer << endl;
    }
}