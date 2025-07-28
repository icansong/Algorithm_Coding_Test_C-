// 소수 & 팰린드롬 수 중에서 최솟값 찾기
#include <iostream>
#include <vector>
#include <cmath>
#include <string>
using namespace std;

bool is_Pal(int target);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    vector<int> A(1000001,1);
    for (int i = 2; i <= sqrt(1000001); i++) {
        int k = 2;
        while (i *k <= 1000001) {
            A[i*k] = 0;
            k++;
        }
    }

    int i = N;
    bool find = false;
    while (find == false) {
        if (A[i] == 1) {
            if (is_Pal(i) == true) {
                cout << i;
                find = true;
            }
        }
        i++;
    }
}

bool is_Pal(int target) {
    string str = to_string(target);
    char const* temp = str.c_str();
    int start = 0;
    int end = str.size() - 1;

    while (start < end) {
        if (temp[start] != temp[end]) {
            return false;
        }
        start++;
        end--;
    }
    return true;
}