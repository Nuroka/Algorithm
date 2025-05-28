#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;


int BFS(vector<vector<int>> &graph, vector<bool> &visited, int source)
{
	queue<int> q;
	q.push(source);
	visited[source] = true;

	int result = 0;

	// 큐가 빌때까지 반복
	while (!q.empty()) {
		int current = q.front();
		q.pop();

		for (int next : graph[current]) {
			// 방문한적 없으면
			if (visited[next]== false) {
				q.push(next);
				visited[next] = true;
				result++;

			}
		}
	}

	return result;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;

	cin >> N >> M;

	vector <vector <int>> node(N+1);
	vector <bool> visited(N+1,false);
	vector <int> res(N + 1);

	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		// 신뢰관계 역전해서 생각하기
		node[b].push_back(a);
	}

	// 각 노드를 한번씩 돌기
	for (int i = 1; i <= N; i++) {
		res[i] = BFS(node, visited, i);
		visited.assign(N + 1, false);
	}
	
	vector <int> res2;
	
	for (int i = 1; i <= N; i++) {
		int tmp = *max_element(res.begin(),res.end());
		if (tmp == res[i]) {
			res2.push_back(i);
		}
	}
	
	sort(res2.begin(), res2.end());

	for (int num : res2) {
		cout << num << ' ';
	}

	return 0;
}
