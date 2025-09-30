#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, K;
int cnt = 0;
int visited[200004];

struct Edge {
	int st;
	int cnt = 0;
};
int BFS(Edge st) {
	queue<Edge> q;
	q.push(st);
	visited[st.st] = 1;

	while (!q.empty()) {
		Edge cur = q.front();
		q.pop();

		for (int i = 0; i < 3; i++) {
			int now = cur.st;
			int now_cnt = cur.cnt;
			
			if (now > 100002 || now < 0)continue;

			// X-1
			if (i == 0) {
				now = now - 1;
				if (visited[now])continue;
				visited[now] = 1;
				now_cnt++;
			}
			// X+1
			else if (i == 1) {
				now = now + 1;
				if (visited[now])continue;
				visited[now] = 1;
				now_cnt++;
			}
			// 2 X
			else {
				now = now * 2;
				if (visited[now])continue;
				visited[now] = 1;
				now_cnt++;
			}

			if (now == K) {
				return now_cnt;
			}
			q.push({ now,now_cnt });
		}
	}

}

int main() {
	cin >> N >> K;
		
	int result;
	if (N == K) {
		result = 0;
	}
	else if (N > K) {
		result = N - K;
	}
	else {
		result = BFS({ N,0 });
	}

	cout << result;

	return 0;
}