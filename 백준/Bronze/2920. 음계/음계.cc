#include <iostream>
using namespace std;

int main() {
    int input[8];
    bool isAscending = true;
    bool isDescending = true;

    // 입력받기
    for (int i = 0; i < 8; i++) {
        cin >> input[i];
    }

    // 정렬 상태 확인
    for (int i = 0; i < 7; i++) {
        if (input[i] < input[i + 1]) {
            isDescending = false;
        } else if (input[i] > input[i + 1]) {
            isAscending = false;
        }
    }

    // 결과 출력
    if (isAscending) {
        cout << "ascending" << endl;
    } else if (isDescending) {
        cout << "descending" << endl;
    } else {
        cout << "mixed" << endl;
    }

    return 0; // 프로그램 정상 종료
}