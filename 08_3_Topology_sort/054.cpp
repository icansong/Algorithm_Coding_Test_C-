// 게임 개발하기
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    vector<vector<int>> A;
    A.resize(N + 1);
    vector<int> Build_time;
    Build_time.resize(N + 1);
    vector<int> indegree;
    indegree.resize(N + 1);

    for (int i = 1; i <= N; i++) {
        cin >> Build_time[i];

        int building_num;
        while (true) {
            cin >> building_num;
            if (building_num == -1) {
                break;
            }
            A[building_num].push_back(i);
            indegree[i]++;
        }
    }

    queue<int> queue;

    vector<int> result;
    result.resize(N + 1);
    for (int i = 1; i <= N; i++) {
        if (indegree[i] == 0) {
            queue.push(i);
            result[i] = Build_time[i];
        }
    }

    while (queue.empty() == false) {
        int now = queue.front();
        queue.pop();
        for (int next : A[now]) {
            indegree[next]--;
            result[next] = max(result[next], result[now] + Build_time[next]);
            if (indegree[next] == 0) {
                queue.push(next);
            }
        }
    }

    for (int i = 1; i <= N; i++) {
        cout << result[i] << "\n";
    }
}