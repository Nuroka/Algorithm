#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N;

	// 입력
	cin >> N;
	vector <int> v(N);
	for (int i = 0; i < N; i++) {
		cin >> v[i];

	}
	
	
	sort(v.begin(), v.end());
	int low = 0;
	int high = N-1;
	int result = 2000000001;
	int left = 0, right = 0;


	while (low != high) {
		int sum = v[low] + v[high];
		if (result > abs(sum)) {
			result = abs(sum);
			left = v[low];
			right = v[high];
		}

		if (sum > 0) {
			high--;
		}
		else {
			low++;
		}

	}
		
	cout << left << ' ' << right;



	return 0;
}

