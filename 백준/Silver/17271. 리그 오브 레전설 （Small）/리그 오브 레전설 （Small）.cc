#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1000000007;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    vector<int> dp(N + 1, 0);
    dp[0] = 1; // 초기 상태

    for (int i = 1; i <= N; ++i) {
        dp[i] = dp[i - 1];
        if (i >= M) {
            dp[i] = (dp[i] + dp[i - M]) % MOD;
        }
    }

    cout << dp[N] << '\n';

    return 0;
}
