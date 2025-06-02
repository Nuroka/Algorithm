#include <iostream>
#include <vector>

using namespace std;

bool DFS(vector<vector<int>>& node, vector<bool>& visited, vector<int>& check, int source, bool& cycle) {
    visited[source] = true;

    for (int next : node[source]) {
        // 방문 안했으면
        if (!visited[next]) {
            // 인접한 노드가 같은 집합이 아니니까 다른 집합으로 처리
            check[next] = (check[source] + 1) % 2;
            DFS(node, visited, check, next, cycle);
        }
        // 이미 방문한 노드가 현재노드와 같은 집합인지(0,1)
        else if (check[next] == check[source]) {
            cycle = true;
        }
    }
    return cycle;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;

    while (T--) {
        int N, M;
        cin >> N >> M;

        vector<vector<int>> node(N + 1);
        for (int i = 0; i < M; i++) {
            int a, b;
            cin >> a >> b;
            node[a].push_back(b);
            node[b].push_back(a);
        }

        vector<bool> visited(N + 1, false);
        vector<int> check(N + 1, 0);
        bool cycle = false;

        for (int i = 1; i <= N; i++) {
            if (!visited[i]) {
                check[i] = 0;
                DFS(node, visited, check, i, cycle);
                if (cycle) break;
            }
        }

        if (cycle) {
            cout << "NO" << endl;
        }
        else {
            cout << "YES" << endl;
        }
    }

    return 0;
}
