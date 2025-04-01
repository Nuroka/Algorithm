#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    vector<long long> v(117);

    v[1] = 1;
    v[2] = 1;
    v[3] = 1;


    for (int i = 4; i <= N; i++) {
        v[i] = v[i - 1] + v[i - 3];
    }
    
    cout << v[N];

    return 0;
}
