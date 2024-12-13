#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

#define arr_size 50000

int main() {
    // 시간 단축을 위한 동기화 비활성화
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    // 초기화
    int a, b = 0;

    // 입력받기
    cin >> a >> b;
    int* c = new int[a];

    for (int i = 0; i < a; i++) {
        cin >> c[i];
    }

    // 정렬
    sort(c, c + a);

    // 출력
    cout << c[b-1];
    

    delete[] c;
    return 0;
}
