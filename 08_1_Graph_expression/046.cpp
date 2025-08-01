// 특정 거리의 도시 찾기
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

void BFS(int node);
static vector<vector<int>> A;
static vector<int> visited;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M, K, X;
    cin >> N >> M >> K >> X;

    A.resize(N + 1);
    for (int i = 0; i < M; i++) {
        int start, end;
        cin >> start >> end;
        A[start].push_back(end);
    }

    visited.resize(N + 1);
    for (int i = 0; i <= N; i++) {
        visited[i] = 0;
    }

    BFS(X);

    vector<int> answer;

    for (int i = 1; i <= N; i++) {
        if (visited[i] == K) {
            answer.push_back(i);
        }
    }

    if (answer.empty() == true) {
        cout << -1;
    }
    else {
        sort(answer.begin(), answer.end());
        for (int i = 0; i < answer.size(); i++) {
            cout << answer[i] << "\n";
        }
    }
}

void BFS(int node) {
    queue<int> myQueue;
    myQueue.push(node);
    visited[node] = 0;

    while (myQueue.empty() == false) {
        int now_node = myQueue.front();
        myQueue.pop();
        for (int i : A[now_node]) {
            if (visited[i] == 0) {
                visited[i] = visited[now_node] + 1;
                myQueue.push(i);
            }
        }
    }
}