// 최소 비용 구하기
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef pair<int,int> edge;
static int N, M;
static vector<int> dist;
static vector<bool> visited;
static vector<vector<edge>> mlist;
int dijkstra(int start, int end);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // N : 도시 개수, M : 버스 개수
    cin >> N >> M;

    // dist : 최단 거리 저장
    dist.resize(N + 1);
    std::fill(dist.begin(), dist.end(), INT_MAX);
    // visited : 노드 방문 여부 저장
    visited.resize(N + 1);
    std::fill(visited.begin(), visited.end(), false);
    // mlist : 도시 -> 도시, 가중치 저장
    mlist.resize(N + 1);

    for (int i = 0; i < M; i++) {
        int start, end, weight;
        cin >> start >> end >> weight;
        mlist[start].push_back(make_pair(end, weight));
    }

    int start_index, end_index;
    cin >> start_index >> end_index;
    int result = dijkstra(start_index, end_index);
    cout << result;

}

int dijkstra(int start, int end) {
    priority_queue<edge, vector<edge>, greater<edge>> pq;
    pq.push(make_pair(0, start));
    dist[start] = 0;

    while (pq.empty() == false) {
        edge now_node = pq.top();
        pq.pop();
        int now = now_node.second;

        if (visited[now] == false) {
            visited[now] = true;
            for (edge n : mlist[now]) {
                if (dist[n.first] > dist[now] + n.second) {
                    dist[n.first] = dist[now] + n.second;
                    pq.push(make_pair(dist[n.first], n.first));
                }
            }
        }
    }
    return dist[end];
}