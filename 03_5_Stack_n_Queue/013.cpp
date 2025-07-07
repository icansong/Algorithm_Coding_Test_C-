// 카드 게임
#include <iostream>
#include <queue>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    queue<int> A;
    for (int i = 1; i <= N; i++) {
        A.push(i);
    }

    while (A.size() > 1) {
        A.pop();
        int k = A.front();
        A.pop();
        A.push(k);
    }

    cout << A.front();
}