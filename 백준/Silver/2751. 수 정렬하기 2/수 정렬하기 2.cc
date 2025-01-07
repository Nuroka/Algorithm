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
	int tmp = 0;
	cin >> N;
	int* v = new int[N];

	for (int i = 0; i < N; i++) {
		cin >> v[i];
	}

	sort(v,v+N);
	
	for (int i = 0; i < N; i++) {
		cout << v[i] << "\n";
	}

	delete[] v;
	return 0;
}
