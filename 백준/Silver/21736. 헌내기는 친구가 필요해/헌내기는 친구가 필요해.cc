#include <iostream>
#include <queue>
#include <string>

using namespace std;

int N, M;
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };
int visited[602][602];
int result = 0;
char MAP[602][602];

struct Edge {
	int y, x;
};

void BFS(Edge st) {
	queue<Edge> q;
	q.push(st);
	visited[st.y][st.x] = 1;

	while (!q.empty()) {
		Edge cur = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = cur.y + dy[i];
			int nx = cur.x + dx[i];

			if (ny < 0 || ny >= N || nx < 0 || nx >= M)continue;
			if (visited[ny][nx])continue;
			if (MAP[ny][nx] == 'X')continue;
			visited[ny][nx] = 1;
			if (MAP[ny][nx] == 'P') {
				result++;
			}
			q.push({ ny,nx });
		}
	}

}
int main() {
	cin >> N >> M;

	string str;
	int st_y, st_x;
	for (int i = 0; i < N; i++) {
		cin >> str;
		for (int j = 0; j < M; j++) {
			MAP[i][j] = str[j];
			if (MAP[i][j] == 'I') {
				st_y = i;
				st_x = j;
			}
		}
	}

	BFS({ st_y,st_x });
	
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (visited[i][j] == 0 && MAP[i][j] == 'P' && result == 0) {
				cout << "TT";
				return 0;
			}
		}
	}

	if (result == 0) {
		cout << "TT";
	}
	else {
		cout << result;
	}

	return 0;
}