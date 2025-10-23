#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int dp[302];
int N;
int v[302];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> v[i];
	}
	
	dp[0] = 0;
	dp[1] = v[1];
	dp[2] = v[1] + v[2];
	dp[3] = max(v[1] + v[3], v[2] + v[3]);
	
	for (int i = 4; i <= N; i++) {
		dp[i] = max(dp[i - 2], dp[i - 3] + v[i-1]) + v[i];
	}

	cout << dp[N];

	return 0;
}