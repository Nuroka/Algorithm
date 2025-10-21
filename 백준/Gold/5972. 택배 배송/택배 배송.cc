#include <iostream>
#include <queue>
#include <vector>

int dist[100000];

using namespace std;

int N, M;

struct Edge {
	int num, cost;
};

struct cmp {
	bool operator()(Edge a, Edge b) {
		return a.cost > b.cost;
	}
};

vector<vector<Edge>> v;

void dijkstra(int st) {
	priority_queue<Edge, vector<Edge>, cmp> pq;
	pq.push({ st,0 });
	dist[st] = 0;
	
	while (!pq.empty()) {
		Edge now = pq.top();
		pq.pop();

		if (dist[now.num] < now.cost)continue;

		for (int i = 0; i < v[now.num].size(); i++) {
			int tar = v[now.num][i].num;
			int next_cost = now.cost + v[now.num][i].cost;

			if (next_cost < dist[tar]) {
				dist[tar] = next_cost;
				pq.push({ tar,next_cost });
			}
		}
	}
}

int main() {
	cin >> N >> M;
	v.resize(N + 1);
	for (int i = 0; i < M; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		v[a].push_back({ b,c });
		v[b].push_back({ a,c });
	}

	for (int i = 0; i <= N; i++) {
		dist[i] = 21e8;
	}

	dijkstra(1);

	cout << dist[N];
	return 0;
}