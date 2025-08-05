// 거짓말쟁이가 되긴 싫어
#include <iostream>
#include <vector>
using namespace std;

static vector<int> parent;

void union_function(int a, int b);
int find(int a);

int main () {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    parent.resize(N+1);
    for (int i = 1; i <= N; i++) {
        parent[i] = i;
    }

    // real_number은 진실을 아는 사람 수
    int real_number;
    cin >> real_number;
    // real_people은 진실을 아는 사람들이 담긴 벡터
    vector<int> real_people(real_number, 0);

    // 진실을 아는 사람이 없다면
    if (real_number == 0) {
        cout << M;
        return 0;
    }

    // 진실을 아는 사람이 있다면
    // for문에서 진실을 아는 사람들을 real_people에 저장
    for (int i = 0; i < real_number; i++) {
        cin >> real_people[i];
    }

    // 파티 정보 저장하는 벡터
    vector<vector<int>> party;
    party.resize(M);
    // 파티에 참여한 사람들을 유니온
    for (int i = 0; i < M; i++) {
        int number;
        cin >> number;
        if (number == 1) {
            int k;
            cin >> k;
            party[i].push_back(k);
        }
        else {
            int a, b;
            cin >> a;
            party[i].push_back(a);
            for (int j = 1; j < number; j++) {
                cin >> b;
                party[i].push_back(b);
                union_function(a, b);
                a = b;
            }
        }
    }


    int result = 0;
    for (int i = 0; i < M; i++) {
        bool isPossible = true;
        for (int j = 0; j < party[i].size(); j++) {
            int compare_people = party[i][j];
            
            for (int k = 0; k < real_number; k++) {
                if (find(compare_people) == find(real_people[k])) {
                    isPossible = false;
                    break;
                }
            }
        }
        if (isPossible == true) {
            result++;
        }
    }

    cout << result;
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