#include <iostream>
#include <cmath> 

int solve(int n, int r, int c) {
    if (n == 0) {
        return 0;
    }

    int half = 1 << (n - 1); 
    int quad_size = half * half;

    if (r < half && c < half) {
        return solve(n - 1, r, c);
    }
    else if (r < half && c >= half) {
        return quad_size + solve(n - 1, r, c - half);
    }
    else if (r >= half && c < half) {
        return 2 * quad_size + solve(n - 1, r - half, c);
    }
    else {
        return 3 * quad_size + solve(n - 1, r - half, c - half);
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int N, r, c;
    std::cin >> N >> r >> c;

    std::cout << solve(N, r, c) << std::endl;

    return 0;
}