// 신기한 소수 찾기
#include <iostream>
#include <vector>
using namespace std;

void DFS(int number, int jarisu);
static int N;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    for (int i : {2,3,5,7}) {
        DFS(i, 1);
    }
}

void DFS(int number, int jarisu) {
    if (jarisu == N) {
        for (int i = 2; i * i <= number; i++) {
            if (number % i == 0) {
                return;
            }
        }
        cout << number << "\n";
        return;
    }

    for (int i = 2; i * i <= number; i++) {
        if (number % i == 0) {
            return;
        }
    }

    for (int i = 1; i <= 5; i++) {
        int update_number = 10 * number + (2*i - 1);
        DFS(update_number, jarisu + 1);
    }
}