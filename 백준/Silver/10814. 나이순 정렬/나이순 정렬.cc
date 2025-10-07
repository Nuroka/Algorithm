#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge {
	int age;
	string name;
};

bool cmp(Edge a, Edge b) {
	return a.age < b.age;
}

int main() {
	int N;
	cin >> N;
	
	vector<Edge> v;
	for (int i = 0; i < N; i++) {
		string str;
		int tmp;

		cin >> tmp >> str;
		v.push_back({ tmp,str });
	}

	stable_sort(v.begin(), v.end(),cmp);

	for (int i = 0; i < N; i++) {
		cout << v[i].age << " " << v[i].name << "\n";
	}

	return 0;
}