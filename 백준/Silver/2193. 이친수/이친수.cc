#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

long long dp[100][10];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;

	cin >> N;

	dp[1][0] = 0;
	dp[1][1] = 1;
	for (int i = 2; i <= N; i++) {
		dp[i][0] = dp[i - 1][0] + dp[i - 1][1];
		dp[i][1] = dp[i - 1][0];
	}

	cout << dp[N][0] + dp[N][1] << endl;

	return 0;
}
