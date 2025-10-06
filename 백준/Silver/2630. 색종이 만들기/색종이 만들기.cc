#include <iostream>
#include <vector>

using namespace std;

int MAP[130][130];
int blue = 0;
int white = 0;

bool is_cut(int y, int x, int n) {
	bool flag = false;
	int first = MAP[y][x];
	for (int i = y; i < y + n; i++)
	{
		for (int j = x; j < x + n; j++)
		{
			if (first != MAP[i][j]) {
				flag = true;
				break;
			}
		}
		if (flag) {
			break;
		}
	}

	return flag;
}

void recur(int y, int x, int N) {
	// 판단
	bool flag = false;
	int first = MAP[y][x];
	for (int i = y; i < y + N; i++)
	{
		for (int j = x; j < x + N; j++)
		{
			if (first != MAP[i][j]) {
				flag = true;
				break;
			}
		}
		if (flag) {
			break;
		}
	}
	if (flag) {
		// 1사분면
		recur(y, x, N / 2);
		// 2사분면
		recur(y, x + N / 2, N / 2);
		// 3사분면
		recur(y + N / 2, x, N / 2);
		// 4사분면
		recur(y + N / 2, x + N / 2, N / 2);
	}
	else {
		if (first == 1) {
			blue++;
		}
		else {
			white++;
		}
	}
}

int main() {
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++){
			cin >> MAP[i][j];
		}
	}

	recur(0,0,N);

	cout << white << "\n";
	cout << blue << "\n";
	return 0;
}