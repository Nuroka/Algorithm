#include <iostream>
#include <queue>

using namespace std;

priority_queue<int> pq;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N;
	cin >> N;

	int tmp;
	for (int i = 0; i < N; i++) {
		cin >> tmp;

		if (tmp == 0) {
			if (pq.empty()) {
				cout << "0\n";
			}
			else {
				cout << pq.top() << "\n";
				pq.pop();
			}
		}
		else {
			pq.push(tmp);
		}

	}


	return 0;
}