#include <iostream>

using namespace std;

int main() {
    //시간 단축을 위한 동기화 비활성화
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin.tie(NULL);

    int N,M;
    //데이터의 개수 줄의 개수
    cin >> N >> M;

    int arr[100001] = { 0 };
    int sum[100001] = { 0 };
    
    //구간합을 구할 대상 배열
    for (int i = 1; i <= N; i++) {
        int a = 0;
        cin >> a;
        arr[i] = a;
    }
    
    //구간합 구해놓기
    for (int i = 1; i <= 100000; i++) {
        sum[i] = sum[i - 1] + arr[i];
    }

    for (int i = 0; i < M; i++) {
        int a, b, c=0;
        cin >> a >> b;
        cout << sum[b] - sum[a-1] << "\n";
    }
   
    return 0;
}