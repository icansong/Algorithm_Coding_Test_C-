// 수를 묶어서 최댓값 만들기
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    vector<int> Positive;
    vector<int> One;
    vector<int> Zero;
    vector<int> Negative;
    int answer = 0;

    for (int i = 0; i < N; i++) {
        int k;
        cin >> k;

        if (k > 1) {
            Positive.push_back(k);
        }
        else if (k == 1) {
            One.push_back(k);
        }
        else if (k == 0) {
            Zero.push_back(k);
        }
        else {
            Negative.push_back(k);
        }
    }

    sort(Positive.begin(), Positive.end());
    if (Positive.size() % 2 == 0) {
        for (int i = 0; i < Positive.size() / 2; i++) {
            answer = answer + Positive[2*i] * Positive[2*i+1];
        }
    }
    else {
        answer += Positive[0];
        for (int i = 0; i < Positive.size() / 2; i++) {
            answer = answer + Positive[2*i+1] * Positive[2*i+2];
        }
    }

    sort(Negative.begin(), Negative.end());
    if (Negative.size() % 2 == 0) {
        for (int i = 0; i < Negative.size() / 2; i++) {
            answer = answer + Negative[2*i] * Negative[2*i+1];
        }
    }
    else {
        if (Zero.size() != 0) {
            for (int i = 0; i < Negative.size() / 2; i++) {
                answer = answer + Negative[2*i] * Negative[2*i+1];
            }
        }
        else {
            answer += Negative[Negative.size()-1];
            for (int i = 0; i < Negative.size() /2; i++) {
                answer = answer + Negative[2*i] * Negative[2*i+1];
            }
        }
    }

    answer = answer + One.size();

    cout << answer;
}