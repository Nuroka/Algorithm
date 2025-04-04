#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

vector<vector<int>> v;
vector<vector<int>> visited;
vector<int> result;
int map[101][101];

void DFS(int N, int x, int y) {
    int nx, ny;
    int dir[4][2] = { {1,0}, {-1,0}, {0,1}, {0,-1} };
    visited[x][y] = 1;

    for (int i = 0; i < 4; i++) {
        nx = x + dir[i][0];
        ny = y + dir[i][1];
        if (nx < 0 || nx >= N || ny < 0 || ny >= N)
            continue;
        if (map[nx][ny] == 0)
            continue;
        if (visited[nx][ny] == 1)
            continue;
        DFS(N, nx, ny);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    int maxHeight = 0;

    cin >> N;
    v.resize(N, vector<int>(N));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> v[i][j];
            maxHeight = max(maxHeight, v[i][j]);
        }
    }

    for (int h = 0; h <= maxHeight; h++) {  
        visited = vector<vector<int>>(N, vector<int>(N, 0));
        int cnt = 0;

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                map[i][j] = (v[i][j] > h) ? 1 : 0;
            }
        }

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (map[i][j] && !visited[i][j]) {
                    DFS(N, i, j);
                    cnt++;
                }
            }
        }

        result.push_back(cnt);
    }

    cout << *max_element(result.begin(), result.end()) << "\n";

    return 0;
}
