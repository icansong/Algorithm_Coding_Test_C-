// 집합 표현하기
#include <iostream>
#include <vector>
using namespace std;

static vector<int> parent;
void union_function(int a, int b);
int find(int a);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    parent.resize(n+1);
    for (int i = 0; i <= n; i++) {
        parent[i] = i;
    }

    for (int i = 0; i < m; i++) {
        int zero_one, a, b;
        cin >> zero_one >> a >> b;

        if (zero_one == 0) {
            union_function(a, b);
        }
        else {
            if (find(a) == find(b)) {
                cout << "YES" << "\n";
            }
            else {
                cout << "NO" << "\n";
            }
        }
    }
}

void union_function(int a, int b) {
    a = find(a);
    b = find(b);

    if (a != b) {
        parent[b] = a;
    }
}

int find(int a) {
    if (a == parent[a]) {
        return a;
    }
    else {
        return parent[a] = find(parent[a]);
    }
}