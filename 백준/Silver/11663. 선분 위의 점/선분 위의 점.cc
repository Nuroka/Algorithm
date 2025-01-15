#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // 초기화 및 입력
    int N, M;
    cin >> N >> M;

    vector<int> dot(N);
    vector<pair<int, int>> line(M);

    // 점 입력
    for (int i = 0; i < N; i++) {
        cin >> dot[i];
    }

    // 선분 입력
    for (int i = 0; i < M; i++) {
        cin >> line[i].first >> line[i].second;
    }

    // 점 정렬
    sort(dot.begin(), dot.end());

    // 선분에 포함된 점 개수 계산
    for (int i = 0; i < M; i++) {
        int x = line[i].first;
        int y = line[i].second;

        // x 이상의 첫 번째 점의 위치
        auto start = lower_bound(dot.begin(), dot.end(), x);
        // y 초과의 첫 번째 점의 위치
        auto end = upper_bound(dot.begin(), dot.end(), y);

        // 포함된 점의 개수
        cout << (end - start) << "\n";
    }

    return 0;
}
