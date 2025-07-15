// 트리의 지름 구하기
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

static vector<vector<pair<int, int>>> A;
static vector<bool> visited;
static vector<int> Distance;
void BFS(int node);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    A.resize(N+1);
    for (int i = 0; i < N; i++) {
        int node1;
        cin >> node1;
        while (true) {
            int node2, dist;
            cin >> node2;
            if (node2 == -1) {
                break;
            }
            cin >> dist;
            A[node1].push_back({node2, dist});
        }
    }

    visited = vector<bool> (N+1,false);
    Distance = vector<int> (N+1,0);

    BFS(1);
    int max_index = 1;
    for (int i = 1; i <= N; i++) {
        if (Distance[i] > Distance[max_index]) {
            max_index = i;
        }
    }

    fill(Distance.begin(), Distance.end(), 0);
    fill(visited.begin(), visited.end(), false);
    BFS(max_index);
    
    sort(Distance.begin(), Distance.end());
    cout << Distance[N];
}

void BFS(int node) {
    queue<int> Q;
    Q.push(node);
    visited[node] = true;

    int sum = 0;
    while (!Q.empty()) {
        int now = Q.front();
        Q.pop();

        sum = Distance[now];
        for (auto& node_n_dist : A[now]) {
            if (!visited[node_n_dist.first]) {
                visited[node_n_dist.first] = true;
                Q.push(node_n_dist.first);
                Distance[node_n_dist.first] = sum + node_n_dist.second;
            }
        }
    }
}