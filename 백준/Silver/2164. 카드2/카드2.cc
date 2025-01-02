#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
using namespace std;



int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	// 초기화
	int N,M;
	int tmp = 0;
	cin >> N;

	// 수열
	queue <int> q;

	// 입력
	for (int i = 1; i <= N; i++) {
		q.push(i);
	}


	for (int i = 1; i <= N-1; i++) {
		
		q.pop();
		q.push(q.front());
		q.pop();
		
	}
	cout << q.front();
	
}
