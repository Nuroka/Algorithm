#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <limits.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	priority_queue<int,vector<int>,greater<int>>pq;

	for (int i = 0; i < N; i++) {
		int tmp;
		cin >> tmp;
		pq.push(tmp);
	}

	int sum = 0;

	while (!pq.empty()) {
		int first = pq.top();
		pq.pop();
		if (pq.empty()) {
			break;
		}
		int second = pq.top();
		pq.pop();
		int merge = first + second;
		sum += merge;
		pq.push(merge);
	}

	cout << sum;
	return 0;
}
