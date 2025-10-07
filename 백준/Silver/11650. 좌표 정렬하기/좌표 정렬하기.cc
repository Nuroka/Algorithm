#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge {
	int x, y;
};

bool cmp(Edge a, Edge b) {
	if (a.x >= b.x) {
		if (a.x == b.x) {
			return a.y < b.y;
		}
		return false;
	}
	else {
		return true;
	}
}

int main() {
	int N;
	cin >> N;

	vector<Edge> v;
	for (int i = 0; i < N; i++) {
		int x, y;
		cin >> x >> y;
		v.push_back({ x,y });
	}

	sort(v.begin(), v.end(), cmp);

	for (int i = 0; i < N; i++) {
		cout << v[i].x << " " << v[i].y << "\n";
	}


	return 0;
}