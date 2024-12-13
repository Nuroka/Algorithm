#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int main() {
    int N;
    cin >> N;
    
    vector<pair<int, int>> v(N);

    for (int i = 0; i < N; i++) {
        cin >> v[i].first;
        v[i].second = i;
    }

    sort(v.begin(),v.end());
    int result = -1;
    for (int i = 0; i < N; i++) {
        if (result < v[i].second - i) {
            result = v[i].second - i;
        }
    }
    cout << result + 1;
    return 0;
}