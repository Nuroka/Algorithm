#include <iostream>
#include <vector>
using namespace std;

static vector <vector <int>> v;
static vector <bool>visited;

// DFS 구현
void DFS(int node) {
	// 만약 방문한 노드면 나오기
	if (visited[node]) {
		return;
	}
	// 들어가면 방문한 노드 true로 바꿔줌
	visited[node] = true;

	// 현재 노드의 인접한 노드를 돌며 방문했는지 확인
	for (int next : v[node]) {
		// 연결한 노드중 방문하지 않은 노드만 탐색
		if (!visited[next]) {
			DFS(next);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// 초기화 및 입력
	int N, M;
	int count = 0;
	cin >> N >> M;

	// vector 크기 조정
	v.resize(N + 1);
	visited.resize(N + 1);

	// 그래프 입력받기
	for (int i = 0; i < M; i++) {
		int s, e;
		cin >> s >> e;
		v[s].push_back(e);
		v[e].push_back(s);
	}

	// DFS 실행 
	for (int i = 1; i <= N; i++) {
		// 방문한 그래프면 중단하고 카운트 늘리고 DFS실행
		if (!visited[i]) {
			count++;
			DFS(i);
		}
	}

	cout << count;

	return 0;

}
