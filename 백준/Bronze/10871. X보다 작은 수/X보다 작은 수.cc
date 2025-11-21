#include <bits/stdc++.h>
using namespace std;
int n, x;
int a[10001];

int main(void){
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	
	cin >> n >> x;
	
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	
	for(int i = 0; i < n; i++){
		if(a[i] < x){
			cout << a[i] << " ";
		}
	}

}