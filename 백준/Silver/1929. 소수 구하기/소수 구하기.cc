#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

void sieve_of_eratosthenes(int M, int N) {
    vector<bool> is_prime(N + 1, true); // N + 1 크기의 소수 판별 배열 생성
    is_prime[0] = is_prime[1] = false; // 0과 1은 소수가 아님

    // 에라토스테네스의 체 알고리즘
    for (int i = 2; i * i <= N; i++) {
        if (is_prime[i]) {
            for (int j = i * i; j <= N; j += i) {
                is_prime[j] = false;
            }
        }
    }

    // 결과 출력
    for (int i = M; i <= N; i++) {
        if (is_prime[i]) {
            cout << i << '\n';
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int M, N;
    cin >> M >> N;

    sieve_of_eratosthenes(M, N);

    return 0;
}
