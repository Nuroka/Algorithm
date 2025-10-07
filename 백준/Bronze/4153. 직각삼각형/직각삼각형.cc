#include <iostream>
#include <cmath>

using namespace std;

int main() {
	while (true) {
		long long a, b, c;
		cin >> a >> b >> c;
		
		if (a == 0 && b == 0 && c == 0) {
			break;
		}

		long long tmp;
		if(a > b){
			tmp = a;
			a = b;
			b = tmp;
		}
		if (b > c) {
			tmp = b;
			b = c;
			c = tmp;
		}

		if (c*c == b*b + a*a) {
			cout << "right" << "\n";
		}
		else {
			cout << "wrong" << "\n";
		}

	}



	return 0;
}