#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

#define MAX 50

vector<vector <int>> v;
vector<vector <bool>> visited(MAX,vector <bool>(MAX,false));



void DFS(int w, int h) {

    visited[w][h] = true;
    // 북 북동 동 남동 남 서남 서 서북
    int dir[8][2] = { {0,1},{1,1},{1,0},{1,-1}, {0,-1}, {-1,-1},{-1,0},{-1,1} };

    for (int i = 0; i < 8; i++)
    {
        int nx = w + dir[i][0];
        int ny = h + dir[i][1];
        if (nx >= 0 && ny >= 0 && nx < MAX && ny < MAX)
        {
            if (v[nx][ny] && !visited[nx][ny])
            {
                visited[nx][ny] = true;
                DFS(nx, ny);
            }
        }
    }
}



int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int w = 1,h = 1;
    int cnt = 0;

    
    while (true)
    {
        cnt = 0;
        cin >> h >> w;

        // 벡터 초기화
        v.assign(w+1, vector<int>(h+1, 0));
        visited.assign(w, vector<bool>(h, false));

        if (w == 0 && h == 0)
        {
            break;
        }

        for (int i = 0; i < w; i++)
        {
            for (int j = 0; j < h; j++)
            {
                int a;
                cin >> a;
                v[i][j] = a;
            }
        }

        
        for (int i = 0; i < w; i++)
        {
            for (int j = 0; j < h; j++)
            {
                if (v[i][j] && !visited[i][j])
                {
                    cnt++;
                    DFS(i, j);
                }
            }
        }
        
        cout << cnt << "\n";


    }
    

    return 0;
}
