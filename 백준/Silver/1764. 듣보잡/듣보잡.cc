#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int N,M;
vector<string>d;
vector<string>b;
vector<string>result;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		string str;
		cin >> str;
		d.push_back(str);
	}
	sort(d.begin(), d.end());
	
	for (int i = 0; i < M; i++) {
		string str;
		cin >> str;
		b.push_back(str);
	}
	sort(b.begin(), b.end());
	
	int cnt = 0;
	// 이분탐색
	for (int i = 0; i < N; i++) {
		bool flag;
		flag = binary_search(b.begin(), b.end(), d[i]);
		if (flag) {
			cnt++;
			result.push_back(d[i]);
		}
	}

	sort(result.begin(), result.end());
	cout << cnt << "\n";
	for (int i = 0; i < result.size(); i++) {
		cout << result[i] << "\n";
	}


	return 0;
}