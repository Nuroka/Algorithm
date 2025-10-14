#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int N, M;
	cin >> N >> M;

	vector<int> v;
	
	int big = 0;
	for (int i = 0; i < N; i++) {
		int tmp;
		cin >> tmp;
		v.push_back(tmp);
		big = max(tmp, big);
	}

	long long left = 0;
	long long right = big;

	long long tmp = 0;
	int result = 0;
	while (left <= right) {
		tmp = (left + right) / 2;
		long long sum = 0;
		// 나무 잘라보기
		for (int i = 0; i < N; i++) {
			if (v[i] > tmp) {
				sum = sum + v[i] - tmp;
			}
		}

		if (sum >= M) {
			result = tmp;
			left = tmp + 1;
		}
		else {
			right = tmp - 1;
		}
		
	}

	cout << result;

	return 0;
}