#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>

using namespace std;

int main()
{
	int N;
	cin >> N;

	priority_queue<int> pq_plus;
	priority_queue<int, vector<int>, greater<int>> pq_minus;

	for (int i = 0; i < N; i++) {
		int tmp;
		cin >> tmp;
		if (tmp > 0) {
			pq_plus.push(tmp);
		}
		else {
			pq_minus.push(tmp);
		}
	}
	
	long long sum = 0;
	int tmp1 = 0;
	int tmp2 = 0;
	while (!pq_plus.empty()) {
		// 우선 하나뽑고
		tmp1 = pq_plus.top();
		pq_plus.pop();

		if (tmp1 == 1) {
			sum += tmp1;
			continue;
		}
		// 큐가 두개 이상 있을 때
		if (!pq_plus.empty()) {
			// 하나 더 뽑고
			tmp2 = pq_plus.top();
			pq_plus.pop();

			if (tmp2 == 1) {
				sum += tmp1 + tmp2;
				continue;
			}

			// 묶어서 곱했을때
			if (tmp1 * tmp2 > tmp1 + tmp2) {
				tmp2 = tmp1 * tmp2;
			}
			// 더했을 때
			else {
				tmp2 = tmp1 + tmp2;
			}
			
			sum += tmp2;
		}
		// 큐가 마지막 큐면 어쩔수없으니 그냥 합
		else {
			sum += tmp1;
		}
	}
	tmp1 = 0;
	tmp2 = 0;
	while (!pq_minus.empty()) {
		// 우선 하나뽑고
		tmp1 = pq_minus.top();
		pq_minus.pop();

		if (tmp1 == 0) {
			continue;
		}
		// 하나 더뽑고
		if (!pq_minus.empty()) {
			tmp2 = pq_minus.top();
			pq_minus.pop();

			if (tmp2 == 0) {
				continue;
			}
			
			// 음수끼리는 무조건 곱하는게 이득
			tmp2 = tmp1 * tmp2;
			sum += tmp2;
		}
		else {
			sum += tmp1;
		}
	}


	cout << sum;

	return 0;
}