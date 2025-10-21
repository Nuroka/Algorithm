#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int LIM = 100000;   // 유효 좌표: 0..100000
const int INF = 1e9;

int N, K;
int dist[LIM + 1];

struct Edge { int num, cost; };
struct cmp { bool operator()(Edge a, Edge b) { return a.cost > b.cost; } };

void dijkstra(int st) {
    priority_queue<Edge, vector<Edge>, cmp> pq;
    dist[st] = 0;
    pq.push({st, 0});

    while (!pq.empty()) {
        Edge now = pq.top(); pq.pop();
        if (now.cost > dist[now.num]) continue;

        if (now.num == K) return; // pop 시점: 최단 확정

        // 0 비용: x*2
        int nx = now.num * 2;
        if (nx <= LIM && dist[nx] > now.cost) {
            dist[nx] = now.cost;
            pq.push({nx, now.cost});
        }
        // 1 비용: x-1
        nx = now.num - 1;
        if (nx >= 0 && dist[nx] > now.cost + 1) {
            dist[nx] = now.cost + 1;
            pq.push({nx, now.cost + 1});
        }
        // 1 비용: x+1
        nx = now.num + 1;
        if (nx <= LIM && dist[nx] > now.cost + 1) {
            dist[nx] = now.cost + 1;
            pq.push({nx, now.cost + 1});
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> K;

    for (int i = 0; i <= LIM; ++i) dist[i] = INF;

    dijkstra(N);
    cout << dist[K] << '\n';
    return 0;
}
