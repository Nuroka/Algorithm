#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>
using namespace std;

int N;
char origin_MAP[52][52];
char MAP[52][52];

int result = 0;

int find_num() {

	int cnt = 1;
	int ret_result = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N - 1; j++) {
			if (MAP[i][j] == MAP[i][j + 1]) {
				cnt++;
			}
			else {
				ret_result = max(ret_result, cnt);
				cnt = 1;
			}
		}
		ret_result = max(ret_result, cnt);
		cnt = 1;
	}

	cnt = 1;
	for (int j = 0; j < N; j++) {
		for (int i = 0; i < N - 1; i++) {
			if (MAP[i][j] == MAP[i + 1][j]) {
				cnt++;
			}
			else {
				ret_result = max(ret_result, cnt);
				cnt = 1;
			}
		}
		ret_result = max(ret_result, cnt);
		cnt = 1;
	}

	return ret_result;
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		string str;
		cin >> str;
		for (int j = 0; j < N; j++) {
			origin_MAP[i][j] = str[j];
		}
	}
	
	memcpy(&MAP, &origin_MAP, sizeof(origin_MAP));
	
	// 가로 swap
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N - 1; j++) {
			char tmp = MAP[i][j + 1];
			MAP[i][j + 1] = MAP[i][j];
			MAP[i][j] = tmp;
			
			// find함수로 찾고
			result = max(result,find_num());

			// MAP 원상복구
			memcpy(&MAP, &origin_MAP, sizeof(origin_MAP));
		}
	}

	// 세로 swap
	for (int j = 0; j < N; j++) {
		for (int i = 0; i < N - 1; i++) {
			char tmp = MAP[i+1][j];
			MAP[i+1][j] = MAP[i][j];
			MAP[i][j] = tmp;

			// find함수로 찾고
			result = max(result, find_num());

			// MAP 원상복구
			memcpy(&MAP, &origin_MAP, sizeof(origin_MAP));
		}
	}

	cout << result;

	return 0;
}