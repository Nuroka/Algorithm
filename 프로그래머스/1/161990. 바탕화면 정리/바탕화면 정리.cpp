#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> wallpaper) {
    // 답안
    vector<int> answer;
    vector<pair<int,int>> v;
    vector<int> x;
    vector<int> y;
    //int rdx=0,rdy=0,lux=0,luy=0;
    
    for(int i = 0; i < wallpaper.size(); i++)
    {
        for(int j = 0; j < wallpaper[0].length(); j++)
        {
            if(wallpaper[i][j] == '#')
            {
                //i,j가 인덱스 위치 
                v.push_back(make_pair(i,j));
                x.push_back(i);
                y.push_back(j);
            }
        }
    }
    auto rdx = *min_element(x.begin(),x.end());
    auto rdy = *min_element(y.begin(),y.end());
    auto lux = *max_element(x.begin(),x.end());
    auto luy = *max_element(y.begin(),y.end());
    answer.push_back(rdx);
    answer.push_back(rdy);
    // 왼쪽위를 좌표로 삼으니까 +1해줘야함
    answer.push_back(lux + 1);
    answer.push_back(luy + 1);
    
    return answer;
}