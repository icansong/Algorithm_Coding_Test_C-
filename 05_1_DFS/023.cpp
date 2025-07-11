// 연결 요소의 개수 구하기
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void DFS(int v);
static vector<vector<int>> A;
static vector<int> B;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    A.resize(N+1);
    for (int i = 0; i < M; i++) {
        int p, q;
        cin >> p >> q;
        A[p].push_back(q);
        A[q].push_back(p);
    }

    // B는 방문 배열, 기본값:0, 0이면 방문X, 1이면 방문O
    B = vector<int>(N+1,0);

    int count = 0;

    for (int i = 1; i <= N; i++) {
        if (B[i] != 1) {
            DFS(i);
            count++;
        }
    }

    cout << count;
}

void DFS(int v) {
    if (B[v] == 1) {
        return;
    }
    B[v] = 1;

    for (int i : A[v]) {
        if (B[i] == 0) {
            DFS(i);
        }
    }
}