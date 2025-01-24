#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

static vector <vector <int>> v;
static vector <bool> visited;
static vector <int> parent;

// DFS 구현
void DFS(int node) {
	// 방문한 노드 true
	visited[node] = true;

	for (int next : v[node]) {
		if (!visited[next]) {
			// parent 노드에 부모 노드를 저장
			parent[next] = node;
			DFS(next);	
		}
	}

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// 초기화 및 입력
	int N;
	int result = 0;
	cin >> N;
	// vector 크기 조정
	v.resize(N + 1);
	visited.resize(N + 1,false);
	parent.resize(N + 1);
	
	// 입력
	for (int i = 1; i < N; i++) {
		int s, e;
		cin >> s >> e;
		v[s].push_back(e);
		v[e].push_back(s);
	}
	
	// 루트를 1이라 가정
	DFS(1);

	// 출력
	for (int i = 2; i < N+1; i++) {
		cout << parent[i] << "\n";
	}


	return 0;

}
