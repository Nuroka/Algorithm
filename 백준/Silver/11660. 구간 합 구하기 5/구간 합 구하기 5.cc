#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	// 초기화
	int N, M;
	int x1, y1, x2, y2 = 0;

	// 2차원 배열의 크기, 구간 합 질의 개수
	cin >> N >> M;

	// 동적할당
	int *result = new int[M];

	// 배열 초기화
	vector<vector<int>> A(N + 1, vector<int>(N + 1, 0));
	vector<vector<int>> sum(N + 1, vector<int>(N + 1, 0));

	// 입력 받기
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> A[i][j];
		}
	}


	// 구간합 구하기
	// 1차원에서는 sum[i] = sum[i-1]+ a[i]
	// 2차원에서는 sum[i][j] = sum[i-1][j] + sum[i][j-1] + a[i][j] - sum[i-1][j-1]
	// 11 =  11
	// 12 =  12 + 11
	// 21 =  21 + 11
	// 22 =  22 + 21 + 12 + 11
	// 31 =  31 + 21 + 11
	// 32 =  32 + 31 + 22 + 21 + 12 + 11
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			sum[i][j] = sum[i - 1][j] + sum[i][j - 1] + A[i][j] - sum[i - 1][j - 1];
		}
	}
	

	// 구간 합 입력
	for (int i = 0; i < M; i++) {
		cin >> x1 >> y1 >> x2 >> y2;
		result[i] = sum[x2][y2] - sum[x1 - 1][y2] - sum[x2][y1 - 1] + sum[x1 - 1][y1 - 1];
	}

	// 결과 출력
	for (int i = 0; i < M; i++) {
		cout << result[i] << ' ';
	}

	// 메모리 해제
	delete[] result;
	return 0;

}