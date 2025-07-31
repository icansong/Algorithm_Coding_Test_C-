// Ax + By = C
#include <iostream>
#include <vector>
using namespace std;

long gcd(long a, long b);
vector<long> Execute(long a, long b);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long A, B, C;
    cin >> A >> B >> C;

    if (C % gcd(A, B) != 0) {
        cout << -1;
    }
    else {
        int mok = int (C / gcd(A, B));
        vector<long> ret = Execute(A, B);
        cout << ret[0] * mok << " " << ret[1] * mok;
    }
}

long gcd(long a, long b) {
    if (b == 0) {
        return a;
    }
    else {
        return gcd(b, a % b);
    }
}

vector<long> Execute(long a, long b) {
    vector<long> ret(2);

    if (b == 0) {
        ret[0] = 1;
        ret[1] = 0;
        return ret;
    }

    long q = a / b;
    vector<long> v = Execute(b, a % b);
    ret[0] = v[1];
    ret[1] = v[0] - v[1] * q;
    return ret;
}