#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    bool n = true; 

    for (int i = 0; i < s.size(); i++) {
        if (s[i] == ' ') {
            n = true; 
        } else {
            if (n) {
                s[i] = toupper(s[i]);
                n = false;
            } else {
                s[i] = tolower(s[i]);
            }
        }
    }
    
    string answer = s;
    return answer;
}

