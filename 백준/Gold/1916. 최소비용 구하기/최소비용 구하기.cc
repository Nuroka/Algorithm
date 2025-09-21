#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N,M;
int st_idx, ed_idx;
struct Edge {
	int num;
	int cost;
};
struct cmp {
	bool operator()(Edge a, Edge b) {
		return a.cost > b.cost;
	}
};

vector<Edge> v[1002];

int dist[1002];

void dijkstra(int st) {
	priority_queue<Edge, vector<Edge>, cmp> pq;
	pq.push({ st,0 });
	dist[st] = 0;

	while (!pq.empty()) {
		Edge cur = pq.top();
		pq.pop();

		if (cur.cost > dist[cur.num])continue;

		for (int i = 0; i < v[cur.num].size(); i++) {
			int tar = v[cur.num][i].num;
			int n_cost = cur.cost + v[cur.num][i].cost;
			if (n_cost < dist[tar]) {
				dist[tar] = n_cost;
				pq.push({ tar,n_cost });
			}
		}
	}
}

int main() {
	cin >> N;
	cin >> M;
	//v.resize(N + 1);
	int a, b, c;
	for (int i = 0; i < M; i++) {
		cin >> a >> b >> c;
		v[a].push_back({ b,c });
	}
	for (int i = 0; i <= N; i++) {
		dist[i] = 21e8;
	}
	cin >> st_idx >> ed_idx;
	dijkstra(st_idx);

	cout << dist[ed_idx];

	return 0;
}