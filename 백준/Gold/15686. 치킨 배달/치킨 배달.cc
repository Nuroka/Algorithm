#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int N, M;
int result = 21e8;

struct Edge {
    int y, x;
};

vector<Edge> house;   
vector<Edge> chicken; 
vector<int> combi;    

int get_distance() {
    int sum = 0;
    for (auto h : house) {
        int dist = 21e8;
        for (int idx : combi) {
            auto c = chicken[idx];
            dist = min(dist, abs(h.y - c.y) + abs(h.x - c.x));
        }
        sum += dist;
    }
    return sum;
}

void DFS(int idx, int lev) {
    if (lev == M) {
        result = min(result, get_distance());
        return;
    }
    for (int i = idx; i < chicken.size(); i++) {
        combi.push_back(i);
        DFS(i + 1, lev + 1);
        combi.pop_back();
    }
}

int main() {
    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int x; cin >> x;
            if (x == 1) house.push_back({ i, j });
            if (x == 2) chicken.push_back({ i, j });
        }
    }

    DFS(0, 0);

    cout << result;
    return 0;
}
