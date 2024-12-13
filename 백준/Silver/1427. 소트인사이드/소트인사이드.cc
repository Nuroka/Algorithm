#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

#define arr_size 50000

// sort의 정책(policy) 설정
bool cmp(char a, char b) {
    return a > b;
}
int main() {
    //시간 단축을 위한 동기화 비활성화
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin.tie(NULL);
    
    //배열 정의
    char n[arr_size];
    cin >> n;
    
    //STL sort 사용
    sort(n, n + strlen(n),cmp);

    //반복문 돌며 출력
    for (int i = 0; i < strlen(n); i++) {
        cout << n[i];
    }
    return 0;
}