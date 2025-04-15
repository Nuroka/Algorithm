#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    int memo[10001] = {0};
    int N, d;
    cin >> N;

    vector <int> v(N+1);

    for (int i = 1; i <= N; i++) {
        cin >> d;
        v[i] = d;
    }

    // 바텀-업 문제
    memo[0] = 0;
    memo[1] = v[1];
    memo[2] = v[1] + v[2];

    for (int i = 3; i <= N; i++) {
        // 숫자를 3개 이상 비교할때는 max({})로 비교가능
        int a = memo[i - 3] + v[i - 1] + v[i];
        int b = memo[i - 2] + v[i];
        int c = memo[i - 1];
        memo[i] = max({a,b,c});
    }

    cout << memo[N];


    return 0;
}
