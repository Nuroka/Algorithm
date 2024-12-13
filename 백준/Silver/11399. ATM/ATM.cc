#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

#define arr_size 1002

int main() {
    //시간 단축을 위한 동기화 비활성화
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin.tie(NULL);
    
    // 초기화
    int N = 0;
    int M[arr_size];
    int sum[arr_size] = { 0 };
    int sum2[arr_size] = { 0 };
    
    // 사람수 입력
    cin >> N;

    // 사람마다 걸리는 시간 입력
    for (int i = 0; i < N; i++) {
        cin >> M[i];
    }

    // 정렬
    sort(M, M + N);

    // 구간합 구하기
    for (int i = 1; i <= N; i++) {
        sum[i] = sum[i - 1] + M[i - 1];
    }

    // 구간합2 구하기
    for (int i = 1; i <= N; i++) {
        sum2[i] = sum2[i - 1] + sum[i];
    }

    // 출력
    cout << sum2[N];
    
    return 0;
}
