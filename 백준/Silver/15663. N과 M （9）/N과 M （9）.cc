#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N, M;
vector<int> v;
int visited[10002];
vector<int> permut;

void DFS(int lev) {
	if (lev == M) {
		for (int i = 0; i < permut.size(); i++) {
			cout << permut[i] << " ";
		}
		cout << "\n";
		return;
	}

	int prev = 0;
	for (int i = 0; i < v.size(); i++) {
		if (!visited[i] && prev != v[i]) {
			visited[i] = 1;
			permut.push_back(v[i]);
			prev = v[i];

			DFS(lev + 1);
			permut.pop_back();
			visited[i] = 0;
		}
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
	
	//v.erase(unique(v.begin(), v.end()), v.end());
	
	DFS(0);


	return 0;
}