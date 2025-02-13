#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T,N;

    // 입력
    vector<pair<int, int>> v;
    //priority_queue<int> pq;

    cin >> T;
    for (int i = 0; i < T; i++) {
        // v 초기화
        cin >> N;
        int max = 0;
        v.resize(N);
        int result = N;

        for (int i = 0; i < N; i++) {
            cin >> v[i].first >> v[i].second;
        } 
        
        // 정렬
        sort(v.begin(), v.end());

        max = v[0].second;
        // N번 돌면서 하위호환이 있는지 확인
        for (int i = 1; i < N; i++) {
            
            //최대 max를 확인하고 업데이트
            if (v[i].second > max) {
                result--;
            }
            else {
                max = v[i].second;

            }

        }
        
        cout << result << '\n';

    }


    
    return 0;
}
