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
    int l,h=0,mid = 0;
    int result = 0;
    cin >> N >> M;

    vector<int> lec(N);

    for (int i = 0; i < N; i++) {
        cin >> lec[i];
        h += lec[i];
    }

    l = *max_element(lec.begin(), lec.end());

    while (l <= h) {
        mid = (l + h) / 2;
        int cnt = 1;
        int sum = 0; 
        for (int i = 0; i < N; i++) {
            if (mid < lec[i]) {
                cnt = mid + 1;
                break;
            }
            if (sum + lec[i] <= mid) {
                sum += lec[i];
            }
            else {
                sum = lec[i];
                cnt++;
            }

        }
        if (cnt <= M) {
            result = mid;
            h = mid - 1;
        }
        else {
            l = mid + 1;
        }
        
    }

    cout << result;

    return 0;
}
