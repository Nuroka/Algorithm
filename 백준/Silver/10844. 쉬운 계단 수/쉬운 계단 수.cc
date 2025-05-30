#include <iostream>
#include <algorithm>
#include <vector>
#define div 1000000000
using namespace std;

int dp[1002][1002];


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;

	cin >> N;

	for (int i = 1; i <= 9; i++) {
		dp[1][i] = 1;
	}

	// dp[i][j] = x
	// i는 구해야할 자리수(N) j는 끝자리의 수 x는 개수
	for (int i = 2; i <= N; i++) {
		for (int j = 0; j <= 9; j++) {
			if (j == 0) {
				dp[i][j] = dp[i - 1][1] % div;
			}
			else if (j == 9) {
				dp[i][j] = dp[i - 1][8] % div;
			}
			else {
				dp[i][j] = (dp[i - 1][j + 1] + dp[i - 1][j - 1]) % div;
			}
		}
	}

	int result = 0;
	for (int i = 0; i <= 9; i++) {
		result = (result + dp[N][i]) % div;
	}


	cout << result << endl;
	

	return 0;
}
