#include <iostream>
#include <algorithm>
#include <vector>
#define div 10007

using namespace std;

int dp[1002][10];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;

	cin >> N;

	for (int i = 0; i <= 9; i++) {
		dp[1][i] = 1;
	}

	for (int i = 0; i <= 9; i++) {
		dp[2][i] = (10 - i) % div;
	}

	for (int i = 3; i <= N; i++) {
		for (int j = 0; j <= 9; j++) {
			int tmp = 0;
			for (int k = j; k <= 9; k++) {
				tmp += dp[i - 1][k];
			}
			dp[i][j] = tmp % div;
		}
	}

	int res = 0;
	for (int i = 0; i <= 9; i++) {
		res = (res + dp[N][i]) % div;
	}

	cout << res;

	return 0;
}
