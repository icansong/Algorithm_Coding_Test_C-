// 최솟값을 만드는 괄호 배치 찾기
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string input;
    cin >> input;

    string num = "";
    int answer = 0;
    int temp = 0;

    bool first = true;

    for (char ch : input) {
        if (isdigit(ch)) {
            num += ch;
        }
        else if (ch == '+') {
            temp += stoi(num);
            num = "";
        }
        else if (ch == '-') {
            temp += stoi(num);
            num = "";

            if (first) {
                answer = temp;
                first = false;
            }
            else {
                answer = answer - temp;
            }

            temp = 0;
        }
    }
    
    if (!num.empty()) {
        temp += stoi(num);
    }

    if (first) {
        answer = temp;
    }
    else {
        answer = answer - temp;
    }

    cout << answer;
}