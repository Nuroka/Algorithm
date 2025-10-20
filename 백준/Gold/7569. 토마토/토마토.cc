#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int MAP[102][102][102];
int visited[102][102][102];

int M, N, H;
// 위, 아래, 왼쪽, 오른쪽, 앞, 뒤
int dy[6] = { 0, 0, 0, 0, -1, 1 };
int dx[6] = { 0, 0, -1, 1, 0, 0 };
int dz[6] = { -1, 1, 0, 0, 0, 0 };

struct Edge { int y, x, z; };

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> M >> N >> H;

	queue<Edge> q;

	for (int k = 0; k < H; k++) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				cin >> MAP[i][j][k];
				if (MAP[i][j][k] == 1) {
					visited[i][j][k] = 1;           
					q.push({ i, j, k });            
				}
			}
		}
	}

	while (!q.empty()) {
		Edge cur = q.front(); q.pop();

		for (int d = 0; d < 6; d++) {
			int ny = cur.y + dy[d];
			int nx = cur.x + dx[d];
			int nz = cur.z + dz[d];

			if (ny < 0 || ny >= N || nx < 0 || nx >= M || nz < 0 || nz >= H) continue;
			if (visited[ny][nx][nz]) continue;
			if (MAP[ny][nx][nz] == -1) continue; 

			visited[ny][nx][nz] = visited[cur.y][cur.x][cur.z] + 1;
			q.push({ ny, nx, nz });
		}
	}

	int result = 0;
	for (int k = 0; k < H; k++) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (MAP[i][j][k] == 0 && visited[i][j][k] == 0) {
					cout << -1;
					return 0;
				}
				result = max(result, visited[i][j][k]);
			}
		}
	}

	cout << max(0, result - 1);
	return 0;
}
