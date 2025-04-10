#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector <int> v;

    int N, a;
    int sum = 1;
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> a;
        v.push_back(a);
    }

    sort(v.begin(), v.end());

    for (int i = 0; i < N; i++) {
        if (v[i] > sum) break;

        sum += v[i];
    }

    cout << sum;


    return 0;
}
