#include <iostream>
#include <vector>

using namespace std;

int N, M;
int visited[10];
vector<int> v;

void DFS(int lev,int cur) {
	if (lev == M) {
		for (int i = 0; i < v.size(); i++) {
			cout << v[i] << " ";
		}
		cout << "\n";
		return;
	}

	for (int i = cur; i <= N; i++) {
		// 만약 직전변수가 
		v.push_back(i);
		DFS(lev + 1,i);
		v.pop_back();
	}
}

int main() {
	cin >> N >> M;
	DFS(0,1);

	return 0;
}