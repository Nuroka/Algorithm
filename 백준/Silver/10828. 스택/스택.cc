#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
	int N;
	cin >> N;

	vector<int>v;
	for (int i = 0; i < N; i++) {
		string str;
		cin >> str;
		if (str == "push") {
			int tmp;
			cin >> tmp;
			v.push_back(tmp);
		}
		else if (str == "top") {
			if (v.empty()) {
				cout << "-1" << "\n";
			}
			else {
				cout << v.back() << "\n";
			}
		}
		else if (str == "size") {
			cout << v.size() << "\n";
		}
		else if (str == "empty") {
			if (v.empty()) {
				cout << "1" << "\n";
			}
			else {
				cout << "0" << "\n";
			}
		}
		else if (str == "pop") {
			if (v.empty()) {
				cout << "-1" << "\n";
			}
			else {
				cout << v.back() << "\n";
				v.pop_back();
			}
		}

	}


	return 0;
}