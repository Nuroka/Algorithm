#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int dp[1002];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, result = 0;
	int T;

	cin >> T;
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;
	dp[4] = 7;
	for (int j = 0; j < T; j++) {
		cin >> N;

		for (int i = 5; i <= N; i++) {
			dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
		}

		cout << dp[N] << endl;
	}

	return 0;
}
