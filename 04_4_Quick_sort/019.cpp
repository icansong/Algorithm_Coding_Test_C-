// k번째 수 구하기
#include <iostream>
#include <vector>
using namespace std;

void quickSort(vector<int> &A, int S, int E, int K);
int partition(vector<int> &A, int S, int E);
void swap(vector<int> &A, int i, int j);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, K;
    cin >> N >> K;

    vector<int> A(N,0);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    
    quickSort(A, 0, N-1, K-1);
    cout << A[K-1];
}

void quickSort(vector<int> &A, int S, int E, int K) {
    int pivot = partition(A, S, E);
    if (pivot == K) {
        return;
    }
    else if (K < pivot) {
        quickSort(A, S, pivot - 1, K);
    }
    else {
        quickSort(A, pivot + 1, E, K);
    }
}

int partition(vector<int> &A, int S, int E) {
    if (S + 1 == E) {
        if (A[S] > A[E]) {
            swap(A, S, E);
        }
        return E;
    }

    int M = (S + E) / 2;
    swap(A, S, M);
    int pivot = A[S];
    int i = S + 1;
    int j = E;

    while (i <= j) {
        while (j >= S+1 && pivot < A[j]) {
            j--;
        }
        while (i <= E && pivot < A[i]) {
            i++;
        }
        if (i < j) {
            swap(A, i++, j--);
        }
        else {
            break;
        }
    }

    A[S] = A[i];
    A[j] = pivot;
    return j;
}

void swap(vector<int> &A, int i, int j) {
    int temp = A[i];
    A[i] = A[j];
    A[j] = temp;
}