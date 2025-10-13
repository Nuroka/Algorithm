#include <iostream>
#include <string>
#include <deque>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;

	while (T--) {
		string func;
		int n;
		string arr;
		cin >> func >> n >> arr;

		deque<int> dq;
		string num;

		// 배열 파싱
		for (int i = 0; i < arr.size(); i++) {
			if (isdigit(arr[i])) num += arr[i];
			else if (!num.empty()) {
				dq.push_back(stoi(num));
				num.clear();
			}
		}

		bool rev = false;
		bool error = false;

		for (char c : func) {
			if (c == 'R') rev = !rev;
			else if (c == 'D') {
				if (dq.empty()) {
					error = true;
					break;
				}
				if (!rev) dq.pop_front();
				else dq.pop_back();
			}
		}

		if (error) {
			cout << "error\n";
			continue;
		}

		cout << "[";
		if (!dq.empty()) {
			if (!rev) {
				for (int i = 0; i < dq.size(); i++) {
					cout << dq[i];
					if (i != dq.size() - 1) cout << ",";
				}
			}
			else {
				for (int i = dq.size() - 1; i >= 0; i--) {
					cout << dq[i];
					if (i != 0) cout << ",";
				}
			}
		}
		cout << "]\n";
	}
	return 0;
}
