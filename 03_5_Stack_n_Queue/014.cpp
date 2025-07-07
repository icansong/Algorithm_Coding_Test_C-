// 절댓값 힙 구현하기
#include <iostream>
#include <queue>
using namespace std;

struct compare {
    // 이 구조가 이해가 안돼, 어쨌든 절댓값이 같으면 작은 값을 우선, 절댓값이 다르면 절댓값이 작은 값을 우선
    bool operator()(int o1, int o2) {
        int first_abs = abs(o1);
        int second_abs = abs(o2);
        if (first_abs == second_abs) {
            return o1 > o2;
        }
        else {
            return first_abs > second_abs;
        }
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    priority_queue<int, vector<int>, compare> MyQueue;

    for (int i = 0; i < N; i++) {
        int request;
        cin >> request;

        if (request == 0) {
            if (MyQueue.empty()) {
                cout << "0" << "\n";
            }
            
            else {
                cout << MyQueue.top() << "\n";
                MyQueue.pop();
            }
        }
        
        else {
            MyQueue.push(request);
        }
    }
}