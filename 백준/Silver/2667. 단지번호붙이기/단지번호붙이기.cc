#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
using namespace std;

int N;
bool visited[26][26];
string MAP[26];
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };

struct Point {
	int y, x;
};

int BFS(Point st) {
	int cnt = 1;
	queue<Point> q;
	q.push(st);
	visited[st.y][st.x] = true;

	while (!q.empty()) {
		Point cur = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = cur.y + dy[i];
			int nx = cur.x + dx[i];

			if (ny < 0 || ny >= N || nx < 0 || nx >= N)continue;
			if (visited[ny][nx])continue;
			if (MAP[ny][nx] == '0')continue;
			visited[ny][nx] = true;
			q.push({ ny,nx });
			cnt++;
		}
	}

	return cnt;
}

int main() {
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> MAP[i];
	}


	vector<int> v;

	// BFS돌면서 찾기
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (MAP[i][j] == '1' && visited[i][j] == false) {
				int tmp = BFS({ i,j });
				v.push_back(tmp);
			}
		}
	}

	sort(v.begin(), v.end());
	cout << v.size() << "\n";
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << "\n";
	}
	return 0;
}