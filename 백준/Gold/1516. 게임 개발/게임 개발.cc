#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// 위상정렬은 첨부터 다시보자
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    // 값 저장하는곳
    vector<int> v(N+1);
    // 그래프
    vector<vector<int>> node(N+1);

    // 진입차수
    vector<int> degree(N + 1,0);

    // 결과물 저장
    vector<int> result(N + 1);

    int tmp1,tmp2;
    for (int i = 1; i <= N; i++) {
        cin >> tmp1;
        v[i] = tmp1;
        while (true) {
            cin >> tmp2;
            if (tmp2 == -1) {
                break;
            }
            node[tmp2].push_back(i);
            degree[i]++;
        }
    }

    // 정렬할 큐
    queue<int> solve;

    // 위상정렬
    for (int i = 1; i <= N; i++) {
        if (degree[i] == 0) {
            solve.push(i);
        }
    }

    while (!solve.empty()) {
        int cur = solve.front();
        solve.pop();
        for (int next : node[cur]) {
            degree[next]--;
            result[next] = max(result[next], result[cur] + v[cur]);
            if (degree[next] == 0) {
                solve.push(next);
            }
        }
    }

    for (int i = 1; i <= N; i++) {
        result[i] += v[i];
        cout << result[i] << endl;
    }

    

    return 0;
}
