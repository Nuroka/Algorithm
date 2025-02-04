#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;
    vector<vector<int>> v(N, vector<int>(M, 0));
    string num;

    for (int i = 0; i < N; i++) {
        cin >> num;
        for (int j = 0; j < M; j++) {
            v[i][j] = num[j] - '0';
        }
    }

    int maxArea = 1; 

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            for (int d = 1; i + d < N && j + d < M; d++) {
                if (v[i][j] == v[i][j + d] && v[i][j] == v[i + d][j] && v[i][j] == v[i + d][j + d]) {
                    maxArea = max(maxArea, (d + 1) * (d + 1));
                }
            }
        }
    }

    cout << maxArea;
    return 0;
}
