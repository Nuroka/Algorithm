#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	// 초기화
	int T,N,M;

	// 테스트 케이스
	cin >> T;
	for (int j = 0; j < T; j++) {
		// 수첩 1 정수개수
		cin >> N;
		vector<int> X(N);
	
		// 수첩 1에 적혀있는 정수들
		for (int i = 0; i < N; i++) {
			cin >> X[i];
		}

		// 수첩 2 정수개수
		cin >> M;
		vector<int> Y(M);
		// 수첩 2에 적혀있는 정수들
		for (int i = 0; i < M; i++) {
			cin >> Y[i];
		}

		int temp = 0;
		sort(X.begin(), X.end());
			for (int i = 0; i < M; i++) {
				if (binary_search(X.begin(), X.end(), Y[i])) {
					cout << 1 << "\n";
				}
				else {
					cout << 0 << "\n";
				}
			}
	}


	return 0;
}
