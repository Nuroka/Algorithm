#include <iostream>
#include <cstring>

using namespace std;

int dpO[100] = { 0 };
int dpI[100] = { 0 };

int main() {
	int T;
	cin >> T;
	int tmp = 2;
	for (int k = 0; k < T; k++) {
		int N;
		cin >> N;

		dpO[0] = 1;
		dpI[0] = 0;
		dpO[1] = 0;
		dpI[1] = 1;

		if (N > tmp && tmp != 0 || tmp != 1) {
			for (int i = 2; i <= N; i++) {
				dpO[i] = dpO[i - 1] + dpO[i - 2];
				dpI[i] = dpI[i - 1] + dpI[i - 2];
			}
		}

		tmp = N;
		cout << dpO[N] << " " <<dpI[N] << "\n";
		//memset(arr, 0, sizeof(arr));
	}

	return 0;
}