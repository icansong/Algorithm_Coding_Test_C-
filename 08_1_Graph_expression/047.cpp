// 효율적으로 해킹하기
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int BFS(int node);
static vector<vector<int>> A;
static vector<bool> visited;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    A.resize(N + 1);
    for (int i = 0; i < M; i++) {
        int p,q;
        cin >> p >> q;
        
        A[q].push_back(p);
    }

    visited.resize(N + 1);

    vector<int> answer(N + 1);
    for (int i = 1; i <= N; i++) {
        fill(visited.begin(), visited.end(), false);
        answer[i] = BFS(i);
    }

    int max = 0;
    for (int i = 1; i <= N; i++) {
        if (answer[i] > max) {
            max = answer[i];
        }
    }

    for (int i = 1; i <= N; i++) {
        if (answer[i] == max) {
            cout << i << " ";
        }
    }
}

int BFS(int node) {
    queue<int> myQueue;
    myQueue.push(node);
    visited[node] = true;

    int count = 0;
    while (myQueue.empty() == false) {
        int now_node = myQueue.front();
        myQueue.pop();
        for (int i : A[now_node]) {
            if (visited[i] == false) {
                visited[i] = true;
                myQueue.push(i);
                count++;
            }
        }
    }
    return count;
}