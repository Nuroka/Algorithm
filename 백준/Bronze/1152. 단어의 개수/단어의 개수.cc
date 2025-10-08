#include <iostream>
#include <cstring>

using namespace std;

char input[1000002];

int main() {
    cin.getline(input, 1000002);  // fgets 대신 cin.getline 사용

    int cnt = 0;
    bool inWord = false;

    for (int i = 0; input[i] != '\0'; i++) {
        if (input[i] != ' ' && !inWord) {
            inWord = true;
            cnt++;
        } else if (input[i] == ' ') {
            inWord = false;
        }
    }

    cout << cnt;

    return 0;
}
