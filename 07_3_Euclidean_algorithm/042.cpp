// 최소 공배수 구하기
#include <iostream>
using namespace std;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;
    
    for (int i = 0; i < T; i++) {
        int A, B;
        cin >> A >> B;
        
        // 큰 수를 A로
        if (A < B) {
            int temp = A;
            A = B;
            B = temp;
        }

        int A_ = A;
        int B_ = B;
        int k = A_ % B_;
        while (k != 0) {
            int temp = k;
            k = B_ % temp;
            B_ = temp;
        }
        int max_divisor = B_;

        cout << A * B / max_divisor << "\n";
    }
}