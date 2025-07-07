// '좋은 수' 구하기
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

    vector<int> A(N,0);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    sort(A.begin(), A.end());

    int sum = 0;
    int count = 0;

    for (int i = 0; i < N; i++) {
        int start_index = 0;
        int end_index = N-1;
        while (start_index < end_index) {
            sum = A[start_index] + A[end_index];

            if (sum == A[i]) {
                if (start_index != i && end_index != i) {
                    count++;
                    break;
                }
                else if (start_index == i) {
                    start_index++;
                }
                else if (end_index == i) {
                    end_index--;
                }
            }

            else if (sum > A[i]) {
                end_index--;
            }

            else {
                start_index++;
            }
        }
    }

    cout << count << "\n";
}