#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int dp[1000002];

int main() {
	int X;
	cin >> X;

	for (int i = 2; i <= X; i++) {

		dp[i] = dp[i - 1] + 1;

		// 2의 배수
		if (i % 2 == 0) {
			dp[i] = min(dp[i], dp[i / 2] + 1);
		}
		// 3의 배수
		if (i % 3 == 0) {
			dp[i] = min(dp[i], dp[i / 3] + 1);
		}
	}

	cout << dp[X];
	return 0;
}