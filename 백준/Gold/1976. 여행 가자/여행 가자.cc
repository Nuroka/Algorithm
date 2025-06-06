#include <iostream>
#include <vector>

using namespace std;

void uni(vector <int>& v, int a, int b);
int finddd(vector <int>& v, int a);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N;
    cin >> M;
    vector <int> v(N + 1);
    vector <int> result(M+1);
    vector <vector<int>> route(N + 1,vector<int>(N+1));
    bool fins = true;

    for (int i = 1; i <= N; i++) {
        v[i] = i;
    }

    
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> route[i][j];
        }
    }
    

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (route[i][j] == 1) {
                
                uni(v, i, j);

            }
        }
    }


    for (int i = 1; i <= M; i++) {
        int tmp;
        cin >> tmp;
        result[i] = tmp;
    }

    for (int i = 2; i <= M; i++) {
        if (finddd(v, result[1]) != finddd(v, result[i])) {
            fins = false;

            break;
        }
    }

    if (fins) {
        cout << "YES" << endl;
    }
    else {
        cout << "NO" << endl;
    }

    return 0;
}

void uni(vector <int>& v, int a, int b) {
    int A = finddd(v, a);
    int B = finddd(v, b);

    if (A != B) {
        v[B] = A;
    }
}

int finddd(vector <int>& v, int a) {
    if (v[a] == a) {
        return a;
    }
    else {
        return v[a] = finddd(v, v[a]);
    }
}