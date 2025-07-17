// 배열에서 K번째 수 찾기
#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N, K;
    cin >> N >> K;

    int start = 1;  
    int end = K;
    int result;

    while (start <= end) {
        int mid = (start + end) / 2;
        int sum = 0;

        for (int i = 1; i <= N; i++) {
            if (mid / i > N) {
                sum = sum + N;
            }
            else {
            sum = sum + mid / i;
            }
        }

        if (sum < K) {
            start = mid + 1;
        }

        else {
            end = mid - 1;
            result = mid;
        }
    }

    cout << result;
}