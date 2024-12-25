#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	// 초기화
	int N;
	int sum = 1, count = 1;
	
	// 입력
	cin >> N;

	int start_index = 1;
	int end_index = 1;


	while (end_index != N) {
		// 답을 찾았을 때
		if (sum == N) {
			count++;
			end_index++;
			sum = sum + end_index;
		}
		// 현재 합이 답보다 클 때
		else if (sum > N) {
			sum = sum - start_index;
			start_index++;
		}
		// 현재 합이 답보다 작을 때
		else {
			end_index++;
			sum = sum + end_index;
		}
	}

	cout << count;


	return 0;

}