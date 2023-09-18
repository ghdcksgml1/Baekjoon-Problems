// 언어 : C++ , (성공/실패) : 1/0 , 메모리 : 2024 KB , 시간 : 0ms
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string.h> // memset

#define ALL(x) begin(x), end(x)
#define pll pair<ll,ll>
#define pii pair<int,int>
#define xx first
#define yy second
#define MAX 1e9

using namespace std;
typedef long long ll;

struct Node {
    int en;     // 도착 정점
    int val;    // 간선의 비용
};

struct compare {
    bool operator()(Node n1, Node n2) {
        return n1.val > n2.val;
    }
};

priority_queue<Node, vector<Node>, compare> pq;
vector<Node> adj[20005];
int dist[20005];

int main(void){
    // 입출력 속도 최적화
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    for (int i=0; i<20005; i++) {
        dist[i] = MAX;
    }

    int V,E,K;
    cin >> V >> E;
    cin >> K;

    while (E--) {
        int u,v,w;
        cin >> u >> v >> w;
        adj[u].push_back({v,w});
    }

    dist[K] = 0;
    pq.push({K, dist[K]});

    while (!pq.empty()) {
        auto cur = pq.top(); pq.pop();
        if (dist[cur.en] != cur.val) continue;
        for (auto nxt : adj[cur.en]) {
            if (dist[nxt.en] <= dist[cur.en] + nxt.val) continue;
            dist[nxt.en] = dist[cur.en] + nxt.val;
            pq.push({nxt.en, dist[nxt.en]});
        }
    }

    for (int i=1; i<=V; i++) {
        if (dist[i] == MAX) cout << "INF\n";
        else cout << dist[i] << '\n';
    }

    return 0;
}