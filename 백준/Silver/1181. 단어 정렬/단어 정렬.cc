#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int N;

bool cmp(string a, string b) {
	if (a.length() <= b.length()) {
		if (a.length() == b.length()) {
			return a < b;
		}
		else {
			return true;
		}
	}
	else {
		return false;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	vector<string> v;

	for (int i = 0; i < N; i++) {
		string tmp;
		cin >> tmp;
		v.push_back(tmp);
	}

	sort(v.begin(), v.end(), cmp);
	v.erase(unique(v.begin(), v.end()), v.end());

	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << "\n";
	}


	return 0;
}