// 친구 관계 파악하기
// 처음에 생각한 구조 => 백트래킹을 고려하지 않아 복잡함
#include <iostream>
#include <vector>
using namespace std;

static vector<vector<int>> A;
static vector<int> B;
static int depth;
static bool found = false;
void DFS(int v);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    A.resize (N);
    for (int i = 0; i < M; i++) {
        int p, q;
        cin >> p >> q;
        A[p].push_back(q);
        A[q].push_back(p);
    }
    
    for (int i = 0; i < N; i++) {
        // 방문하면 1, 방문하지 않은 상태 0
        B = vector<int>(N,0);
        depth = 1;

        DFS(i);
        if (found) {
            cout << 1;
            return 0;
        }
    }
    cout << 0;
}

void DFS(int v){
    if (found) {
        return;
    }
    
    if (depth == 5) {
        found = true;
        return;
    }

    B[v] = 1;
    for (int i : A[v]) {
        if (B[i] == 0) {
            depth++;
            DFS(i);

            depth --; // 백트래킹
        }
    }
    B[v] = 0; // 백트래킹
}