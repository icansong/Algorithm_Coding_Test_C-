// 임계 경로 구하기
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // N: 도시 수, M: 도로 수
    int N, M;
    cin >> N >> M;

    vector<vector<pair<int,int>>> A;
    A.resize(N + 1);
    vector<int> indegree;
    indegree.resize(N + 1);
    vector<vector<pair<int,int>>> reverseA;
    reverseA.resize(N + 1);
    for (int i = 0; i < M; i++) {
        int start, end, time;
        cin >> start >> end >> time;
        A[start].push_back(make_pair(end, time));
        reverseA[end].push_back(make_pair(start, time));
        indegree[end]++;
    }

    int start_city, end_city;
    cin >> start_city >> end_city;

    queue<int> myqueue;
    myqueue.push(start_city);
    vector<int> result;
    result.resize(N + 1);

    while (myqueue.empty() == false) {
        int now = myqueue.front();
        myqueue.pop();

        for (pair<int,int> next : A[now]) {
            indegree[next.first]--;
            result[next.first] = max(result[next.first], result[now] + next.second);
            if (indegree[next.first] == 0) {
                myqueue.push(next.first);
            }
        }
    }
    cout << result[end_city] << "\n";

    int count = 0;
    vector<bool> visited;
    visited.resize(N + 1);
    queue<int> myqueue_re;
    myqueue_re.push(end_city);
    visited[end_city] = true;

    while (myqueue_re.empty() == false) {
        int now = myqueue_re.front();
        myqueue_re.pop();

        for (pair<int,int> next : reverseA[now]) {
            if (result[next.first] + next.second == result[now]) {
                count++;
                if (visited[next.first] == false) {
                    visited[next.first] = true;
                    myqueue_re.push(next.first);
                }
            }
        }
    }
    cout << count;
}