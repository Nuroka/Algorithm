#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M;
int visited[102];
int result = 0;

struct Edge {
	int x,y;
};

struct Point {
	int cur;
	int cost;
};

vector<Edge> radder;
vector<Edge> snake;

int is_rad(int st) {
	for (int i = 0; i < radder.size(); i++) {
		if (st == radder[i].x) {
			return radder[i].y;
		}
	}
	return 0;
}

int is_sna(int st) {
	for (int i = 0; i < snake.size(); i++){
		if (st == snake[i].x) {
			return snake[i].y;
		}
	}
	return 0;
}

void BFS(Point st) {
	queue<Point> q;
	q.push(st);
	visited[st.cur] = 1;

	while (!q.empty()) {
		Point cur = q.front();
		q.pop();

		for (int i = 1; i <= 6; i++) {
			int n_point = cur.cur + i;
			int n_cost = cur.cost + 1;

			if (visited[n_point])continue;
			visited[n_point] = 1;
			if (n_point > 100)continue;
			
			int tmpr = is_rad(n_point);
			if (tmpr != 0) {
				n_point = tmpr;
				visited[n_point] = 1;
			}

			int tmps = is_sna(n_point);
			if (tmps != 0) {
				n_point = tmps;
				visited[n_point] = 1;
			}

			if (n_point == 100) {
				result = n_cost;
				return;
			}
			q.push({ n_point,n_cost });
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	// 입력
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		int x,y;
		cin >> x >> y;
		radder.push_back({ x,y });
	}
	for (int i = 0; i < M; i++) {
		int x, y;
		cin >> x >> y;
		snake.push_back({ x,y });
	}

	BFS({1,0});

	cout << result;

	return 0;
}