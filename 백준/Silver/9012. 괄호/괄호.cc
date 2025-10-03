#include <iostream>
#include <vector>

using namespace std;

int N;

int main() {
	cin >> N;

	for (int i = 0; i < N; i++) {
		string str;
		int cnt = 0;
		cin >> str;
		for (int j = 0; j < str.size(); j++) {
			if (str[j] == '(') {
				cnt++;
			}
			else {
				cnt--;
			}

			if (cnt < 0) {
				cnt = -1;
				break;
			}

		}
		if (cnt == 0) {
			cout << "YES" << "\n";
		}
		else {
			cout << "NO" << "\n";
		}

	}




	return 0;
}