#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <limits.h>

#define INF INT_MAX

using namespace std;

typedef pair<int, int> pr;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N,K;
	cin >> N >> K;

	vector<int> v(N+1);

	for (int i = 0; i < N; i++) {
		cin >> v[i];
	}

	int sum = 0;
	int cnt = 0;
	int idx = N-1;
	while (sum < K) {
		if (sum + v[idx] > K) {
			idx--;
			continue;
		}
		else {
			sum += v[idx];
			cnt++;
		}

	}

	cout << cnt;
	

	return 0;
}
