#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>

using namespace std;

vector <vector<int>> v;
vector <bool> visited;

void DFS(int node) {
	cout << node << " ";
	visited[node] = true;
	for (int i : v[node]) {
		if (!visited[i]) {
			DFS(i);
		}
	}
}
void BFS(int node) {
	queue<int> q;
	q.push(node);
	visited[node] = true;

	while (!q.empty()) {
		int now_node = q.front();
		q.pop();
		cout << now_node << " ";
		for (int i : v[now_node]) {
			if (!visited[i]) {
				visited[i] = true;
				q.push(i);
			}
		}
	}

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N,M,V;

	// 입력
	cin >> N>>M>>V;
	

	v.resize(N + 1);

	for (int i = 0; i < M; i++) {
		int s, e;
		cin >> s >> e;
		v[s].push_back(e);
		v[e].push_back(s);
	}
	for (int i = 1; i <= N; i++) {
		sort(v[i].begin(), v[i].end());
	}

	visited = vector<bool>(N + 1, false);

	DFS(V);
	cout << "\n";
	fill(visited.begin(), visited.end(), false);
	BFS(V);
	cout << "\n";



	return 0;
}

