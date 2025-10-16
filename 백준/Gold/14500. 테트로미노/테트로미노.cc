#include <iostream>
#include <algorithm>
using namespace std;

int N, M;
int MAP[502][502];
int visited[502][502];

int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };
int result = 0;

struct Edge {
	int y, x;
	int cost;
};

void DFS(Edge st, int lev) {
	if (lev == 4) {
		result = max(result, st.cost);
		return;
	}
	
	for (int i = 0; i < 4; i++) {
		int ny = st.y + dy[i];
		int nx = st.x + dx[i];

		if (ny < 0 || ny >= N || nx < 0 || nx >= M)continue;
		if (visited[ny][nx])continue;
		visited[ny][nx] = 1;
		DFS({ ny,nx,st.cost + MAP[ny][nx] }, lev + 1);
		visited[ny][nx] = 0;
	}
}

int T(int y,int x) {
	int res = 0;
	// ㅓ
	if (x - 1 >= 0 && y - 1 >= 0 && y + 1 < N)
		res = max(res, MAP[y][x - 1] + MAP[y - 1][x] + MAP[y][x] + MAP[y + 1][x]);
	// ㅏ
	if (x + 1 < M && y - 1 >= 0 && y + 1 < N)
		res = max(res, MAP[y][x + 1] + MAP[y - 1][x] + MAP[y][x] + MAP[y + 1][x]);
	// ㅗ
	if (x - 1 >= 0 && y - 1 >= 0 && x + 1 < M)
		res = max(res, MAP[y][x - 1] + MAP[y - 1][x] + MAP[y][x] + MAP[y][x + 1]);
	// ㅜ
	if (x - 1 >= 0 && y + 1 < N && x + 1 < M)
		res = max(res, MAP[y][x - 1] + MAP[y + 1][x] + MAP[y][x] + MAP[y][x + 1]);

	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> MAP[i][j];
		}
	}

	int ans = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			visited[i][j] = 1;
			DFS({ i,j }, 0);
			visited[i][j] = 0;
			result = max(result, T(i,j));
		}
	}
	
	cout << result;


	return 0;
}