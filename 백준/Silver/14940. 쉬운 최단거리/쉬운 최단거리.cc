#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M;
int MAP[1002][1002];
int visited[1002][1002];
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };

struct Edge {
	int y, x;
};

void BFS(Edge st) {
	queue<Edge> q;
	q.push(st);
	visited[st.y][st.x] = 0;

	while (!q.empty()) {
		Edge cur = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = cur.y + dy[i];
			int nx = cur.x + dx[i];
			if (ny < 0 || ny >= N || nx < 0 || nx >= M)continue;
			if (visited[ny][nx]) continue;
			if (MAP[ny][nx] == 0) continue;
			visited[ny][nx] = visited[cur.y][cur.x] + 1;
			q.push({ ny,nx });
		}
	}
}

int main() {
	cin >> N >> M;
	int start_y = 0, start_x = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++){
			cin >> MAP[i][j];
			if (MAP[i][j] == 2) {
				start_y = i;
				start_x = j;
			}
		}
	}

	BFS({start_y,start_x});
	visited[start_y][start_x] = 0;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (visited[i][j] == 0 && MAP[i][j] == 1) {
				cout << "-1" << " ";
			}
			else {
				cout << visited[i][j] << " ";
			}
		}
		cout << "\n";
	}

	return 0;
}