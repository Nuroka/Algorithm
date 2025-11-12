#include <iostream>
#include <queue>

using namespace std;

long long s, ed;

struct Edge {
	long long num;
	int dist;
};

int BFS(Edge st) {
	queue<Edge> q;
	q.push({st});

	while (!q.empty()) {
		Edge cur = q.front();
		q.pop();

		if (cur.num == ed) return cur.dist;
		if (cur.num * 2 <= ed) {
			q.push({ cur.num * 2,cur.dist + 1 });
		}
		if (cur.num * 10 + 1 <= ed) {
			q.push({ (cur.num * 10) + 1,cur.dist + 1 });
		}
	}
	return -1;
}

int main() {
	cin >> s >> ed;
	int result = 0;
	if (s > ed) {
		cout << -1;
	}
	else {
		result = BFS({s,1});
		cout << result;
	}
	
	return 0;
}