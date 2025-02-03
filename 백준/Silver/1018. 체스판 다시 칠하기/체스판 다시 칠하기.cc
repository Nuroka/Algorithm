#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

char v[51][51];

char white_board[8][8] = {
	'W','B','W','B','W','B','W','B',
	'B','W','B','W','B','W','B','W',
	'W','B','W','B','W','B','W','B',
	'B','W','B','W','B','W','B','W',
	'W','B','W','B','W','B','W','B',
	'B','W','B','W','B','W','B','W',
	'W','B','W','B','W','B','W','B',
	'B','W','B','W','B','W','B','W'
};
char black_board[8][8] = {
	'B','W','B','W','B','W','B','W',
	'W','B','W','B','W','B','W','B',
	'B','W','B','W','B','W','B','W',
	'W','B','W','B','W','B','W','B',
	'B','W','B','W','B','W','B','W',
	'W','B','W','B','W','B','W','B',
	'B','W','B','W','B','W','B','W',
	'W','B','W','B','W','B','W','B'
};

int white_first(int x, int y) {
	int result = 0;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (v[x + i][y + j] != white_board[i][j])
				result++;
		}
	}
	return result;
}

int black_first(int x, int y) {
	int result = 0;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (v[x + i][y + j] != black_board[i][j])
				result++;
		}
	}
	return result;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int M, N , result = 64;
	cin >> M >> N;
	
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			cin >> v[i][j];
		}
	}

	int white, black;
	for (int i = 0; i <= M - 8; i++) {
		for (int j = 0; j <= N - 8; j++) {
			white = white_first(i, j);
			black = black_first(i, j);
			if (white < black) {
				result = (white < result) ? white : result;
			}
			else {
				result = (black < result) ? black : result;
			}
		}
	}
	
	cout << result << '\n';

	return 0;
}

