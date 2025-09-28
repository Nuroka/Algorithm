#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>

using namespace std;

int N, M;
int MAP[1002][1002];
int visited[1002][1002];
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };

struct Point {
	int y, x;
};

vector<Point> v;

// visited로 다돌았는지 확인
void BFS() {
	queue<Point> q;
	for (int i = 0; i < v.size(); i++) {
		Point st = v[i];
		visited[st.y][st.x] = 1;
		q.push(st);
	}
	

	while (!q.empty()) {
		Point cur = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = cur.y + dy[i];
			int nx = cur.x + dx[i];

			if (ny < 0 || ny >= N || nx < 0 || nx >= M)continue;
			if (MAP[ny][nx] == -1) continue;
			if (visited[ny][nx])continue;
			visited[ny][nx] = visited[cur.y][cur.x] + 1;

			q.push({ ny,nx });

		}
	}

}

int main() {
	cin >> M >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> MAP[i][j];
			if (MAP[i][j] == 1) {
				v.push_back({ i,j });
			}

		}
	}
	BFS();

	int day = 0;
	bool flag = false;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			day = max(visited[i][j], day);
			
			if (visited[i][j] == 0 && MAP[i][j] == 0) {
				flag = true;
			}
		}
	}

	if (flag) {
		cout << -1;
	}
	else {
		cout << day - 1;
	}

	return 0;
}