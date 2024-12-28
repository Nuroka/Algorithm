#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	// 초기화
	int N,M;
	int count = 0;
	int start_index = 0, end_index = 0;

	// 입력
	cin >> N;
	cin >> M;

	vector<int> list(N, 0);

	
	// 재료 입력받기 
	for (int i = 0; i < N; i++) {
		cin >> list[i];
	}

	// 정렬
	sort(list.begin(), list.end());
	
	end_index = N - 1;

	while (start_index < end_index) {
		// 합이 M보다 클 때
		if (list[start_index] + list[end_index] > M) {
			end_index--;
		}
		// 합이 M보다 작을 때
		else if(list[start_index] + list[end_index] < M){
			start_index++;
		}
		// 합이 M
		else {
			count++;
			start_index++;
			end_index--;
		}
	}

	
	cout << count << '\n';

	return 0;

}

