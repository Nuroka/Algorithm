#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int N;

struct compare {
	bool operator()(int a, int b) {
		return a > b;
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	priority_queue<int, vector<int>, compare> pq;
	cin >> N;

	int x;

	for (int i = 0; i < N; i++) {
		cin >> x;
		if (x > 0) {
			pq.push(x);

		}
		else if (x == 0) {
			if (pq.empty()) {
				cout << 0 << "\n";
			}
			else {
				cout << pq.top() << "\n";
				pq.pop();
			}
		}

	}
	
	return 0;

}