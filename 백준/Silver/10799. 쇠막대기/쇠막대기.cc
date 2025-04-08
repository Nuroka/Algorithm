#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string v;

    int cnt = 0;
    int pip = 0;

    cin >> v;


    for (int i = 0; i <= v.size(); i++) {
        if (v[i] == '(' && v[i + 1] == ')')
        {
            cnt = cnt + pip;
            i++;
        }
        else if (v[i] == '(')
        {
            pip++;
        }
        else if (v[i] == ')')
        {
            cnt++;
            pip--;
        }
        else {
            break;
        }
    }
    cout << cnt;

    return 0;
}
