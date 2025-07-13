// BFS와 DFS 프로그램
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

static vector<vector<int>> A;
static vector<bool> visited;
static bool arrive;
void DFS(int node);
void BFS(int node);

int main () {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M, start;
    cin >> N >> M >> start;

    arrive = false;
    
    A.resize(N+1);

    for (int i = 0; i < M; i++) {
        int p, q;
        cin >> p >> q;
        A[p].push_back(q);
        A[q].push_back(p);
    }

    for (int i = 1; i <= N; i++) {
        sort(A[i].begin(), A[i].end());
    }

    visited = vector<bool>(N+1, false);

    DFS(start);
    cout << "\n";
    fill(visited.begin(), visited.end(), false);
    BFS(start);
    cout << "\n";
}

void DFS(int node) {
    cout << node << " ";
    visited[node] = true;

    for (int i : A[node]) {
        if (!visited[i]) {
            DFS(i);
        }
    }
}

void BFS(int node) {
    queue<int> Q;
    Q.push(node);
    visited[node] = true;

    while (!Q.empty()) {
        int now = Q.front();
        Q.pop();
        cout << now << " ";
        for (int i : A[now]) {
            if (!visited[i]) {
                visited[i] = true;
                Q.push(i);
            }
        }
    }
}