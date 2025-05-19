#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	vector<int> v(N);
	for (int i = 0; i < N; i++) {
		cin >> v[i];
	}

	stack<int> s;
	vector<char> result;
	int idx = 0;

	for (int i = 1; i <= N; i++) {
		s.push(i);
		result.push_back('+');

		while (!s.empty() && s.top() == v[idx]) {
			s.pop();
			result.push_back('-');
			idx++;
		}
	}

	if (!s.empty()) {
		cout << "NO\n";
	}
	else {
		for (char c : result) {
			cout << c << "\n";
		}
	}

	return 0;
}