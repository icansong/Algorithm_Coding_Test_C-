// 친구 관계 파악하기
#include <iostream>
#include <vector>
using namespace std;

static vector<vector<int>> A;
static vector<int> B;
static bool found = false;
void DFS(int v, int depth);

int main () {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    A.resize(N);
    for (int i = 0; i < M; i++) {
        int p, q;
        cin >> p >> q;
        A[p].push_back(q);
        A[q].push_back(p);
    }

    B = vector<int> (N,0);
    for (int i = 0; i < N; i++) {
        DFS(i, 1);
        if (found) {
            cout << 1;
            return 0;
        }
    }
    cout << 0;
}

void DFS (int v, int depth) {
    if (depth == 5 || found == true) {
        found = true;
        return;
    }

    B[v] = 1;

    for (int i : A[v]) {
        if (B[i] != 1) {
            DFS(i, depth + 1);
        }
    }
    B[v] = 0;
}