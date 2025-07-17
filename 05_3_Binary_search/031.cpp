// 배열에서 K번째 수 찾기
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, K;
    cin >> N >> K;

    vector<int> B(N*N+1,0);
    int k = 1;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            B[k] = i*j;
            k++;
        }
    }
    sort(B.begin(), B.end());
    cout << B[K];
}