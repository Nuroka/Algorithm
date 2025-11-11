#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int dp[502][502];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N;
	cin >> N;
	
	vector<int> v[502];
	int tmp;
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < i; j++) {
			cin >> tmp;
			v[i].push_back(tmp);
		}
	}
	// 위에서 내려가면서 더하기
	// 맨 마지막 4 5 2 6 5에서 가장 큰거

	dp[1][0] = v[1].back();
	// i는 y층
	for (int i = 1; i < N; i++) {
		// j는 x축의 개수
		for (int j = 0; j < i; j++) {

			// 밑으로 내려가면서 3갈래로 나누어짐
			for (int k = 0; k < 2; k++) {
				if (j + k < 0 || j + k > i)continue;
				tmp = dp[i][j] + v[i+1][j+k];
				dp[i + 1][j + k] = max(dp[i + 1][j + k], tmp);

			}

		}
	}

	int result = *max_element(dp[N], dp[N] + N);
	cout << result;

	return 0;
}