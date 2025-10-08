#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int H, M;
	cin >> H >> M;

	if (M >= 45) {
		M = M - 45;
	}
	else {
		if (H == 0) {
			H = 23;
			M = 60 - (45 - M);
		}
		else {
			H = H - 1;
			M = 60 - (45 - M);
		}
	}

	cout << H << " " << M;

	return 0;
}