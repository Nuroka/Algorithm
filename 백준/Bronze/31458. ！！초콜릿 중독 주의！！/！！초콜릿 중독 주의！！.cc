#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string str;

    int left_cnt = 0, right_cnt = 0;
    int cnt = 0;
    int result = 0;
    int T;

    cin >> T;

    for(int i = 0; i < T; i++)
    {
        cin >> str;
        
        // 문자열에서 숫자 찾기
        for (int j = 0; j < str.size(); j++)
        {
            if (str[j] == '1' || str[j] == '0') {
                left_cnt = j;
                if (str[j] == '1') {
                    result = 1;
                }
                else {
                    result = 0;
                }
            }
        }

        right_cnt = str.size() - left_cnt - 1;
        cnt = right_cnt - left_cnt;
        

        for (int j = 0; j < right_cnt; j++) {
            result = 1;
        }

        for (int j = 0; j < left_cnt; j++) {
            result = !result;
        }
        
        cout << result<<"\n";
    }

    return 0;
}
