// 블루레이 만들기
#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    vector<int> A(N,0);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    
    // start는 벡터 A의 최대, end는 벡터 A의 원소들을 모두 더한 합
    int start = A[0];
    int end = A[0];
    for (int i = 1; i < N; i++) {
        if (A[0] < A[i]) {
            start = A[i];
        }
        end = end + A[i];
    }

    int result = end;

    while (start <= end) {
        int mid = (start + end) / 2;
        int sum = 0;
        int number = 1;

        for (int i = 0; i < N; i++) {
            sum = sum + A[i];
            if (sum > mid) {
                sum = A[i];
                number++;
            }
        }

        if (number < M) {
            end = mid - 1;
        }
        else if (number > M) {
            start = mid + 1;
        }
        else if (number == M) {
            if (result > mid) {
                result = mid;
            }
            end = mid - 1;
        }
    }

    cout << result;
}