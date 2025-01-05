#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
#include <cmath>
using namespace std;

// 비교 함수 선언 
// abs(n1) : n1의 절댓값을 반환하는 함수
struct cmp{
	bool operator()(int n1, int n2) {
		// 절대값이 같다면 더 작은 값에 우선순위를 높게
		if (abs(n1) == abs(n2))
			return n1 > n2;
		// 절댓값이 더 작은 값에 우선순위를 높게 주고
		return abs(n1) > abs(n2);
	}
};


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	// 초기화
	int N;
	int tmp = 0;
	
	// 입력
	cin >> N;

	// 우선순위큐
	priority_queue<int,vector<int>,cmp> x;
	// 결과 저장해 놓을 큐
	queue <int> q;

	for (int i = 0; i < N; i++) {
		cin >> tmp;
		// x가 0이 아닐때
		if (tmp != 0) {
			x.push(tmp);
		}
		// x가 0일 때
		else {
			// 큐가 비어있지 않을 때
			if (!x.empty()) {
				q.push(x.top());
				x.pop();
			}
			// 큐가 비어있을 때
			else
				q.push(0);
		}
	}

	// 결과 출력
	while (!q.empty()) {
		cout << q.front() << endl;
		q.pop();
	}
	return 0;
}
