#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
#include <string>

using namespace std;

int N;
string MAP[102];
int visited[102][102];
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };

struct Point {
	int y, x;
	char color;
};

// visited로 다돌았는지 확인
void BFS(Point st) {
	queue<Point> q;
	q.push(st);
	visited[st.y][st.x] = 1;


	while (!q.empty()) {
		Point cur = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = cur.y + dy[i];
			int nx = cur.x + dx[i];
			
			if (ny < 0 || ny >= N || nx < 0 || nx >= N)continue;
			if (MAP[ny][nx] != cur.color) continue;
			if (visited[ny][nx])continue;
			visited[ny][nx] = 1;

			q.push({ ny,nx,cur.color });

		}
	}

}

void RGBFS(Point st) {
	queue<Point> q;
	q.push(st);
	visited[st.y][st.x] = 1;


	while (!q.empty()) {
		Point cur = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = cur.y + dy[i];
			int nx = cur.x + dx[i];

			if (ny < 0 || ny >= N || nx < 0 || nx >= N)continue;
			if (MAP[ny][nx] != cur.color) continue;
			if (visited[ny][nx])continue;
			visited[ny][nx] = 1;

			q.push({ ny,nx,cur.color });

		}
	}

}
int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> MAP[i];
	}
	
	int cnt = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (visited[i][j] == 0) {
				BFS({ i,j,MAP[i][j]});
				cnt++;
			}
		}
	}

	memset(visited, 0, sizeof(visited));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (MAP[i][j] == 'G' || MAP[i][j] == 'R') {
				MAP[i][j] = 'C';
			}
		}
	}

	int RGcnt = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (visited[i][j] == 0) {
				BFS({ i,j,MAP[i][j] });
				RGcnt++;
			}
		}
	}
	cout << cnt << " " << RGcnt;


	return 0;
}