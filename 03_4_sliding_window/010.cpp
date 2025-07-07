// 최솟값 찾기 1
#include <iostream>
#include <deque>
using namespace std;

int main() {
    int N, L;
    cin >> N >> L;
    
    deque<pair<int,int>> dq;
    for (int i = 0; i < N; i++) {
        int temp;
        cin >> temp;

        while (!dq.empty() && dq.back().first > temp) {
            dq.pop_back();
        }
        dq.push_back({temp, i});

        if (i - dq.front().second >= L) {
            dq.pop_front();
        }
        cout << dq.front().first << " ";
    }
}