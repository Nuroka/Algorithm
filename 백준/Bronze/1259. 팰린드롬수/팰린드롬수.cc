#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
	
	while (true) {
		string str;
		cin >> str;
		if (str == "0") {
			break;
		}
		
		bool flag = false;
		for (int i = 0; i < str.size(); i++) {
			if (str[i] != str[str.size()-1-i]) {
				flag = true;
			}
		}
		
		if (flag) {
			cout << "no\n";
		}
		else {
			cout << "yes\n";
		}

	}



	return 0;
}