// 버블 정렬 프로그램 2
#include <iostream>
#include <vector>
using namespace std;

void merge_sort(int start, int end);
static vector<int> A;
static vector<int> tmp;
static int answer;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    A = vector<int>(N,0);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    tmp = vector<int>(N,0);

    answer = 0;
    merge_sort(0, N-1);

    cout << answer;
}

void merge_sort(int start, int end) {
    if (end <= start) {
        return;
    }

    else {
        int mid = (start + end) / 2;

        merge_sort(start, mid);
        merge_sort(mid + 1, end);

        for (int i = start; i <= end; i++) {
            tmp[i] = A[i];
        }

        int k = start;
        int index1 = start;
        int index2 = mid + 1;

        while (index1 <= mid && index2 <= end) {
            if (tmp[index1] <= tmp[index2]) {
                A[k] = tmp[index1];
                k++;
                index1++;
            }
            else {
                A[k] = tmp[index2];
                k++;
                index2++;
                answer = answer + (index2 - k);
            }
        }

        while (index1 <= mid) {
            A[k] = tmp[index1];
            k++;
            index1++;
        }

        while (index2 <= end) {
            A[k] = tmp[index2];
            k++;
            index2++;
        }
    }
}