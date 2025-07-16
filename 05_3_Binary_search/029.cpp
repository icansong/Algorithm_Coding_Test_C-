#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N;

    vector<int> A(N+1,0);
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
    }
    sort(A.begin(), A.end());

    cin >> M;

    for (int i = 0; i < M; i++) {
        int target;
        cin >> target;

        int start_index = 1;
        int end_index = N;

        bool find = false;

        while (start_index <= end_index) {
            int mid_index = (start_index + end_index) / 2;
            int mid_number = A[mid_index];

            if (mid_number > target) {
                end_index = mid_index - 1;
            }
            else if (mid_number < target) {
                start_index = mid_index + 1;
            }
            else {
                find = true;
                break;
            }
        }

        if (find == true) {
            cout << 1 << "\n";
        }
        else {
            cout << 0 << "\n";
        }
    }
}