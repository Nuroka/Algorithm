#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <limits.h>

#define INF INT_MAX

using namespace std;

typedef pair<int, int> pr;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int V, E;
	cin >> V >> E;
	int K;
	cin >> K;

	// 그래프
	vector<vector<pr>> graph(V+1);
	// 방문했는지 확인
	vector<bool>visited(V+1,false);
	// 시작노드부터 목적지까지 거리 담는 배열 (결과 배열)
	vector<int> dist(V + 1,INF);
	// 우선순위큐(오름차순)
	priority_queue <pr,vector<pr>,greater<pr>> pq;

	for (int i = 0; i < E; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		graph[u].push_back(make_pair(v, w));
	}

	// 우선순위큐에 시작정점 삽입
	pq.push(make_pair(0, K));
	// 시작점 초기화, 초기배열에서 시작점 0으로 세팅
	dist[K] = 0;


	// pq에서 first는 누적거리 dist[next]
	// second는 해당 정점의 번호 next
	while (!pq.empty()) {
		pr current = pq.top();
		pq.pop();

		// 정점 번호
		int cur_v = current.second;
		// 방문한 노드인지 확인
		if (visited[cur_v]) {
			continue;
		}

		// 방문 안했으면 true로 바꾸고 탐색
		visited[cur_v] = true;

		for (int i = 0; i < graph[cur_v].size(); i++) {
			// 1->(2,2)  1->(3,3)
			pr tmp = graph[cur_v][i];
			int next = tmp.first;
			int value = tmp.second;


			if (dist[next] > dist[cur_v] + value) {
				dist[next] = dist[cur_v] + value;
				pq.push(make_pair(dist[next], next));
			}
		}

		
		
		
	}


	for (int i = 1; i <= V; i++) {
		if (dist[i]==INF) {
			cout << "INF" << endl;
		}
		else {
			cout << dist[i]<<endl;
		}
	}
	return 0;
}
