// 회의실 배정하기
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

    vector<pair<int,int>> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i].second;
        cin >> A[i].first;
    }

    sort(A.begin(), A.end());

    int answer = 0;

    int end_time = 0;
    for (int i = 0 ; i < N; i++) {
        if (A[i].second >= end_time) {
            answer++;
            end_time = A[i].first;
        }
    }

    cout << answer;
}