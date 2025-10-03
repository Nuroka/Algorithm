#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
	int N;
	cin >> N;

	queue<int> q;

	for (int i = 0; i < N; i++) {
		string tmp;
		cin >> tmp;
		int x = 0;
		if (tmp == "push") {
			cin >> x;
			q.push(x);
		}
		else if (tmp == "pop") {
			if (q.empty()) {
				cout << "-1" << "\n";
			}
			else {
				cout << q.front() << "\n";
				q.pop();
			}
		}
		else if (tmp == "size") {
			cout << q.size() << "\n";
		}
		else if (tmp == "empty") {
			if (q.empty()) {
				cout << "1" << "\n";
			}
			else {
				cout << "0" << "\n";
			}
		}
		else if (tmp == "front") {
			if (q.empty()) {
				cout << "-1" << "\n";
			}
			else {
				cout << q.front() << "\n";
			}
		}
		else if (tmp == "back") {
			if (q.empty()) {
				cout << "-1" << "\n";
			}
			else {
				cout << q.back() << "\n";
			}
		}	
	}

	return 0;
}