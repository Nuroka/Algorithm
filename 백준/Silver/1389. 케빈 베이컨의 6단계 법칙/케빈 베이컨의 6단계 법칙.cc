#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;

int N, M;
vector<vector<int>> v;
int visited[102];
int cnt = 0;
int max_count = 0;
int max_num = 21e8;
int countt = 0;
int MAP[102][102];


struct Edge {
	int tar;
	int cost;
};
void DFS(int lev, int goal) {
	if (lev == goal) {
		max_num = min(countt, max_num);
		return;
	}

	for (int i = 0; i < v[lev].size(); i++) {
		int cur = v[lev][i];
		if (visited[cur])continue;
		visited[cur] = 1;
		countt++;
		DFS(cur,goal);
		countt--;
		visited[cur] = 0;
	}
}

int BFS(Edge st,int ed) {
	queue<Edge> q;
	q.push(st);
	visited[st.tar] = 1;

	while (!q.empty()) {
		Edge cur = q.front();
		q.pop();
		for (int i = 0; i < v[cur.tar].size(); i++) {
			int tar = v[cur.tar][i];
			int n_cost = cur.cost + 1;
			if (tar == ed) {
				return n_cost;
			}
			if (visited[tar])continue;
			visited[tar] = 1;
			q.push({tar,n_cost});
		}
	}
}


int main() {
	cin >> N >> M;
	v.resize(N+1);
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
		MAP[a][b] = 1;
		MAP[b][a] = 1;
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (i == j)continue;
			if (MAP[i][j])continue;
			if (MAP[j][i])continue;
			max_num = 21e8;
			countt = BFS({i,0}, j);
			memset(visited, 0, sizeof(visited));
			MAP[i][j] = countt;
			MAP[j][i] = countt;
			//DFS(i,j);
			//MAP[i][j] = max_num;
			//MAP[j][i] = max_num;
		}
	}

	int result = 21e8;
	int flag_num = 0;
	for (int i = 1; i <= N; i++) {
		int finale = 0;
		for (int j = 1; j <= N; j++){
			if (i == j)continue;
			finale += MAP[i][j];
		}
		if (result > finale) {
			result = finale;
			flag_num = i;
		}
	}


	cout << flag_num;

	return 0;
}