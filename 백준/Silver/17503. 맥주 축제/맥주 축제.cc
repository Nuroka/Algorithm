#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

bool compare(const pair<long, long>& a, const pair<long, long>& b) {
    if (a.first == b.first) {
        return a.second > b.second;
    }

    return a.first < b.first;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M, K;
    int max = 0;
    int sum = 0;

    // 입력
    cin >> N >> M >> K;
    vector<pair<long, long>> v(K);
    priority_queue<long long> pq;


    for (int i = 0; i < K; i++) {
        cin >> v[i].second >> v[i].first;
        
    }

    // second 값 기준으로 정렬
    sort(v.begin(), v.end(),compare);


    //// N일동안 
    //for (int i = 0; i < K-N+1; i++) {
    //    max = 0;
    //    sum = 0;
    //    // 슬라이딩 하면서 N개의 값 저장
    //    for (int j = i; j < N+i; j++) {
    //        sum += v[j].first;
    //        pq.push(v[j].second);
    //        if (max < v[j].second) {
    //            max = v[j].second;
    //        }
    //    }
    //    // 만약 sum이 M보다 크거나 같고 새로운 최소레벨값을 찾았으면 
    //    if (sum >= M) {
    //        // 최고 레벨을 저장
    //        if (result > max || result == -1) {
    //            result = max;

    //        }
    //    }
    //}

    for (int i = 0; i < K; i++) {
        pq.push(-v[i].second);
        sum += v[i].second;

        if (pq.size() > N) {
            sum += pq.top();
            pq.pop();
        }

        if (pq.size() == N && sum >= M) {
            cout << v[i].first;
            return 0;
        }
    }

    cout << -1;
    
    return 0;
}
