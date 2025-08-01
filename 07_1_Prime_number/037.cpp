// 소수 구하기
#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int M, N;
    cin >> M >> N;

    vector<int> A(N+1,0);
    for (int i = M; i <= N; i++) {
        A[i] = 1;
    }

    for (int i = 2; i <= N; i++) {
        int k = 2;
        while (i * k <= N) {
            A[i*k] = 0;
            k++;
        }
    }

    for (int i = M; i <= N; i++) {
        if (A[i] == 1) {
            cout << i << "\n";
        }
    }
}

/* solution
#include <cmath> 
int main () {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int M, N;
    cin >> M >> N;
    vector<int> A(N+1);

    for (int i = 2; i <= N; i++) {
        A[i] = i;
    }
    for (int i = 2; i <= sqrt(N); i++) {
        if (A[i] == 0) {
            continue;
        }
        for (int j = i + i; j <= N; j = j + i) {
            A[j] = 0;
        }
    }

    for (int i = M; i <= N; i++) {
        if (A[i] != 0) {
            cout << A[i] << "\n";
        }
    }
}
*/