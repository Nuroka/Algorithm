#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
vector<int> v;
vector<int> permut;

int visited[10002];

void DFS(int lev) {
	if (lev == M) {
		for (int i = 0; i < permut.size(); i++) {
			cout << permut[i] << " ";
		}
		cout << "\n";
		return;
	}

	for (int i = 1; i <= N; i++) {
		if (visited[i])continue;
		visited[i] = 1;
		permut.push_back(v[i - 1]);
		DFS(lev + 1);
		permut.pop_back();
		visited[i] = 0;

	}
}

int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		int tmp;
		cin >> tmp;
		v.push_back(tmp);
	}
	sort(v.begin(), v.end());

	DFS(0);

	return 0;
}