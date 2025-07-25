// 수를 묶어서 최댓값 만들기
#include <iostream>
#include <queue>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    // 내림차순
    priority_queue<int> Positive;
    // 오름차순
    priority_queue<int, vector<int>, greater<int>> Negative;
    int one = 0;
    int zero = 0;

    for (int i = 0; i < N; i++) {
        int data;
        cin >> data;

        if (data > 1) {
            Positive.push(data);
        }
        else if (data == 1) {
            one++;
        }
        else if (data == 0) {
            zero++;
        }
        else {
            Negative.push(data);
        }
    }

    int sum = 0;

    while (Positive.size() > 1) {
        int first = Positive.top();
        Positive.pop();
        int second = Positive.top();
        Positive.pop();
        sum = sum + first * second;
    }

    if (!Positive.empty()) {
        sum = sum + Positive.top();
        Positive.pop();
    }

    while (Negative.size() > 1) {
        int first = Negative.top();
        Negative.pop();
        int second = Negative.top();
        Negative.pop();
        sum = sum + first * second;
    }

    if (!Negative.empty()) {
        if (zero == 0) {
            sum = sum + Negative.top();
            Negative.pop();
        }
    }

    sum = sum + one;
    cout << sum;
}