#include <iostream>
#include <vector>

using namespace std;

vector<int> parent;
vector<int> rankk;

// find 함수 (경로 압축)
int find(int a) {
    if (parent[a] != a) {
        parent[a] = find(parent[a]);
    }
    return parent[a];
}

// union 함수 (유니온 바이 랭크)
void union_sets(int a, int b) {
    a = find(a);
    b = find(b);

    if (a == b) return;

    // 랭크를 비교해 더 작은 랭크를 큰 랭크 쪽으로 붙임
    if (rankk[a] < rankk[b]) {
        parent[a] = b;
    }
    else if (rankk[a] > rankk[b]) {
        parent[b] = a;
    }
    else {
        parent[b] = a;
        rankk[a]++;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    parent.resize(N + 1);
    rankk.resize(N + 1, 0);

    for (int i = 0; i <= N; i++) {
        parent[i] = i;
    }

    for (int i = 0; i < M; i++) {
        int op, a, b;
        cin >> op >> a >> b;

        if (op == 0) { // union
            union_sets(a, b);
        }
        else { // find
            if (find(a) == find(b)) {
                cout << "YES\n";
            }
            else {
                cout << "NO\n";
            }
        }
    }

    return 0;
}
