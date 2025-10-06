#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N,M;
int visited[102];
vector<vector<int>> v;

void BFS(int st) {
	queue<int> q;
	q.push(st);
	visited[st] = 1;

	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		for (int i = 0; i < v[cur].size(); i++) {
			int next = v[cur][i];
			if (visited[next])continue;
			visited[next] = 1;
			q.push(next);
		}
	}

}

int main() {
	cin >> N;
	cin >> M;

	v.resize(N + 1);

	for (int i = 0; i < M; i++) {
		int a,b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}


	BFS(1);
	int cnt = 0;
	for (int i = 1; i <= N; i++) {
		if (visited[i] == 1) {
			cnt++;
		}
	}

	cout << cnt - 1;


	return 0;
}