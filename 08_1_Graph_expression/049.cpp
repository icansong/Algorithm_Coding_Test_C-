// 물의 양 구하기
#include <iostream>
#include <queue>
using namespace std;

void BFS();
// Sender -> Receiver 경우 6가지
static int Sender[] = {0,0,1,1,2,2};
static int Receiver[] = {1,2,0,2,0,1};

static bool visited[201][201];
static bool answer[201];
// A, B, C 물의 양을 저장
static int now[3];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> now[0] >> now[1] >> now[2];
    BFS();

    for (int i = 0; i < 201; i++) {
        if (answer[i]) {
            cout << i << " ";
        }
    }
}

void BFS() {
    queue<pair<int,int>> queue;
    queue.push(make_pair(0,0));
    visited[0][0] = true;
    answer[now[2]] = true;

    while (queue.empty() == false) {
        pair<int, int> p = queue.front();
        queue.pop();

        int A = p.first;
        int B = p.second;
        int C = now[2] - A - B;

        for (int k = 0; k < 6; k++) {
            int next[] = {A, B, C};
            next[Receiver[k]] += next[Sender[k]];
            next[Sender[k]] = 0;

            // 물이 용량보다 많아 넘칠 때
            if (next[Receiver[k]] > now[Receiver[k]]) {
                next[Sender[k]] = next[Receiver[k]] - now[Receiver[k]];
                next[Receiver[k]] = now[Receiver[k]];
            }

            if (visited[next[0]][next[1]] == false) {
                visited[next[0]][next[1]] = true;
                queue.push(make_pair(next[0], next[1]));

                if (next[0] == 0) {
                    answer[next[2]] = true;
                }
            }
        }
    }
}