#include <iostream>

using namespace std;

int N, M;
int visited[10];


void DFS(int lev, int cur) {
	if (lev == M) {
		for (int i = 1; i <= 9; i++) {
			if (visited[i] == 0) continue;
			cout << visited[i] << " ";
		}
		cout << "\n";
		return;
	}

	for (int i = cur; i <= N; i++) {
		if (visited[i])continue;
		visited[i] = i;
		DFS(lev + 1, i);
		visited[i] = 0;
	}
}

int main() {
	cin >> N >> M;
	DFS(0,1);

	return 0;
}