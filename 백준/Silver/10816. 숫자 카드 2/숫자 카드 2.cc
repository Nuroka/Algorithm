#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
	int N,M;
	cin >> N;
	vector<int> find;
	for (int i = 0; i < N; i++) {
		int tmp;
		cin >> tmp;
		find.push_back(tmp);
	}
	vector<int> v;
	cin >> M;
	for (int i = 0; i < M; i++){
		int tmp;
		cin >> tmp;
		v.push_back(tmp);
	}

	sort(find.begin(), find.end());
	vector<int> result(M + 1,0);
	for (int i = 0; i < M; i++) {
		if (binary_search(find.begin(), find.end(), v[i])) {
			auto tmp = (upper_bound(find.begin(), find.end(), v[i]) - find.begin()) - (lower_bound(find.begin(), find.end(), v[i]) - find.begin());
			result[i] = tmp;
		}
	}

	for (int i = 0; i < M; i++){
		cout << result[i] << " ";
	}
	
	return 0;
}