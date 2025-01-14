#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(int a, int b) {
	return a > b;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	// 초기화 및 입력
	int K, N;
	int tmp,result = 0;
	long long mid = 0;
	long long high, low = 1;

	cin >> K >> N;

	vector <int> v(K);

	for (int i = 0; i < K; i++) {
		cin >> v[i];
	}

	// 정렬
	sort(v.begin(), v.end(),cmp);
	high = v[0];

	// 이분탐색
	while (low <= high) {
		mid = (low + high) / 2;
		int cnt = 0;
		for (int i = 0; i < K; i++)
			cnt += v[i] / mid;
		
		if (cnt >= N) {
			low = mid + 1;
			if (result < mid) {
				result = mid;
			}
		}
		else {
			high = mid - 1;
		}
	}

	cout << result;
	return 0;
}
