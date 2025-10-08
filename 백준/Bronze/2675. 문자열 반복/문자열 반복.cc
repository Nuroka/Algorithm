#include <iostream>
#include <string>

using namespace std;

int main() {
	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		int P;
		string str;
		cin >> P >> str;
		
		for (int j = 0; j < str.size(); j++) {
			for (int k = 0; k < P; k++) {
				cout << str[j];
			}
		}

		cout << "\n";
	}

	return 0;
}