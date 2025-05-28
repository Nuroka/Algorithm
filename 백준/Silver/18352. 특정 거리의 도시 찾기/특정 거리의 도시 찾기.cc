#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

void BFS(vector<vector<int>> &graph, vector<int> &distance, int source)
{
	queue<int> q;
	q.push(source);
	distance[source] += 1;

	// 큐가 빌때까지 반복
	while (!q.empty()) {
		int current = q.front();
		q.pop();

		for (int next : graph[current]) {
			// 방문한적 없으면
			if (distance[next]== -1) {
				distance[next] = distance[current] + 1;
				q.push(next);
			}
		}
	}

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M, K, X;


	cin >> N >> M >> K >> X;
	vector <vector <int>> node(N+1);
	vector <int> visited(N+1,-1);
	vector <int> result;

	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		node[a].push_back(b);
	}

	// BFS하면서 경로 지날때마다 +1
	// 경로가 K가 될경우 break
	BFS(node, visited, X);

	for (int i = 0; i <= N; i++) {
		if (visited[i] == K) {
			result.push_back(i);
		}
	}

	if (result.empty()) {
		cout << -1 << endl;
	}
	else {
		sort(result.begin(), result.end());
		for (int num : result) {
			cout << num << endl;
		}
	}

	return 0;
}
