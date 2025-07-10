// 수 정렬하기 3
#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    int count[100001] = {0};
    int number = 0;

    for (int i = 0; i < N; i++) {
        cin >> number;
        count[number]++;
    }

    for (int i = 0; i < 100001; i++) {
        if (count[i] != 0) {
            for (int j = 0; j < count[i]; j++) {
                cout << i << "\n";
            }
        }
    }
}