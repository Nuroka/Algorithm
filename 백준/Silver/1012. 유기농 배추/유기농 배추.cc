#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
#include <string>
using namespace std;

static vector <vector <int>> v;
static vector <vector <int>> visited;

// DFS 구현
void DFS(int wide, int height, int x,int y) {
	int nx, ny;
	int dir[4][2] = { {1,0} , {-1,0}, {0,1} ,{0,-1} };
	// 들어가면 방문한 노드 true로 바꿔줌
	visited[x][y] = 1;

	// 현재 노드의 인접한 노드 동서남북을 돌며 방문했는지 확인
	for(int i = 0; i < 4; i++){
		nx = x + dir[i][0];
		ny = y + dir[i][1];
		if (nx < 0 || nx >= wide || ny < 0 || ny >= height)
			continue;
		if (v[nx][ny] == 0) 
			continue;
		if (visited[nx][ny] == 1)
			continue;
		
		DFS(wide,height,nx, ny);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// 초기화 및 입력
	int T;
	int result = 0;
	cin >> T;
	for (int i = 0; i < T; i++) {
		int M, N, K;
		cin >> M >> N >> K;
		v.clear();
		v.assign(M, vector<int>(N,0));
		visited.assign(M, vector<int>(N));

		result = 0;

			
		for (int j = 0; j < K; j++) {
			int x, y;
			cin >> x >> y;
			v[x][y] = 1;
		}

		for (int k = 0; k < M; k++) {
			for (int z = 0; z < N; z++) {
				if (v[k][z] == 1 && visited[k][z] == 0) {
					DFS(M,N,k, z);
					result++;
				}
			}
		}
		cout << result << " ";
		
	}

	return 0;

}
