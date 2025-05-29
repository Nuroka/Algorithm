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
	cin >> N;

	dp[1] = 1;
	dp[2] = 3;
	
	//dp[i] = dp[i-1] + dp[i-2] + dp[i-2]
	for (int i = 2; i <= N; i++) {
		dp[i+1] = (dp[i] + dp[i - 1] + dp[i - 1]) % 10007;
	}

	cout << dp[N]%10007;

	return 0;
}
