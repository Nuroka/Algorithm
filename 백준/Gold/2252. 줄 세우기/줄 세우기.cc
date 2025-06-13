#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// 답보고 한거
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    int result = 0;
    cin >> N >> M;

    // 진입차수
    vector<int> v(N+1);
    vector<vector<int>> node(N+1);
 

    for (int i = 0; i < M; i++) {
        int tmp1,tmp2;
        cin >> tmp1 >> tmp2;
        node[tmp1].push_back(tmp2);
        v[tmp2]++;
    }


    // 정렬할 큐
    queue<int> solve;

    // 위상정렬
    for (int i = 1; i <= N; i++) {
        if (v[i] == 0) {
            solve.push(i);
        }
    }

    while (!solve.empty()) {
        int cur = solve.front();
        solve.pop();
        cout << cur << " ";
        for (int next : node[cur]) {
            v[next]--;
            if (v[next] == 0) {
                solve.push(next);
            }
        }
    }

    return 0;
}
