#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long N,cat = 1;
    int cnt = 1;
    cin >> N;


    while (true) {
        if (cat >= N) {
            break;
        }

        cat = cat * 2;
        cnt++;
    }

    if (N == 0) {
        cnt = 0;
    }
    
    cout << cnt;


    return 0;
}
