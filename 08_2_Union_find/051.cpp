// 여행 계획 짜기
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

    int N, M;
    cin >> N >> M;

    parent.resize(N+1);
    for (int i = 1; i <= N; i++) {
        parent[i] = i;
    }

    int city[201][201];
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> city[i][j];
        }
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (city[i][j] == 1) {
                union_function(i, j);
            }
        }
    }

    bool connect = true;
    int compare;
    for (int i = 0; i < M; i++) {
        int k;
        cin >> k;

        if (i != 0) {
            if (compare != find(k)) {
                connect = false;
                cout << "NO";
                break;
            }
        }
        compare = find(k);
    }

    if (connect == true) {
        cout << "YES";
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