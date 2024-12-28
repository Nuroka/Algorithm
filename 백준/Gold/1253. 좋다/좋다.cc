#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	// 초기화
	int N;
	int count = 0;
	int start_index = 0, end_index = 1;
	long sum;
	// 입력
	cin >> N;

	vector<int> list(N, 0);

	for (int i = 0; i < N; i++) {
		cin >> list[i];
	}

	// 정렬
	sort(list.begin(), list.end());

	// 이 문제는 굳이 따지면 포인터 3개
	// 좋은수 포인터, 투포인터
	// 첫 for문에서 좋은 수 포인터
	for (int sum = 0; sum < N; sum++) {
		// 인덱스 초기화
		start_index = 0;
		end_index = N - 1;
		
		while (start_index < end_index) {
			// 합이 찾으려는 좋은수보다 크면 end포인터 감소
			if (list[start_index] + list[end_index] > list[sum]) {
				end_index--;
			}

			// 합이 찾으려는 좋은수보다 작으면 start포인터 증가
			else if (list[start_index] + list[end_index] < list[sum]) {
				start_index++;
			}
			// 합이 찾으려는 좋은수임 hit!!
			else {
				// 이 때 포인터가 좋은수에 가있으면 안되니까 확인 hit!!
				if (start_index != sum && end_index != sum) {
					count++;
					break;
				}
				// 합은 좋은수인데 포인터가 좋은수포인터와 겹칠때
				else if (start_index == sum) {
					start_index++;
				}
				else if (end_index == sum) {
					end_index--;
				}
			}
		}
	}
	
	cout << count;


	return 0;

}

