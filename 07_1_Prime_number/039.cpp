// 소수 & 팰린드롬 수 중에서 최솟값 찾기
#include <iostream>
#include <vector>
#include <cmath>
#include <string>
using namespace std;

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

    bool find = false;
    int i = N;
    while (find == false) {
        if (A[i] == 1) {
            string str;
            str = to_string(i);                 // 숫자 i를 문자 str로 변환
            char const* temp = str.c_str();     // 문자 str을 char 배열 형태로 변환
            int start = 0;
            int end = str.size() - 1;

            bool is_pal = true;

            while (start < end) {
                if (temp[start] != temp[end]) {
                    is_pal = false;
                    break;
                }
                start++;
                end--;
            }
            
            if (is_pal == true) {
                cout << i;
                find = true;
            }
        }
        i++;
    }
}