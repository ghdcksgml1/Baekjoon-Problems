// 언어 : C++ , (성공/실패) : 1/0 , 메모리 : 2024 KB , 시간 : 0ms
#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h> // memset
#include <queue>

using namespace std;

#define X first
#define Y second

int v,e,st;

// {비용, 정점 번호}
vector<pair<int,int>> adj[20005];
const int INF = 1e9+10;
int d[20005];

int main(void){
    // 입출력 속도 최적화
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin>>v>>e>>st;
    fill(d,d+v+1,INF);

    while(e--){
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].push_back({w,v});
    }
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    d[st] = 0;
    pq.push({d[st],st});

    while(!pq.empty()){
        auto cur = pq.top(); pq.pop();
        if(d[cur.Y] != cur.X) continue; // 거리가 다르면 원소를 버린다.
        for(auto nxt: adj[cur.Y]){
            if(d[nxt.Y] <= d[cur.Y]+nxt.X) continue;
            d[nxt.Y] = d[cur.Y] + nxt.X;
            pq.push({d[nxt.Y],nxt.Y});
        }
    }

    for(int i=1;i<=v;i++){
        if(d[i] == INF) cout << "INF\n";
        else cout<<d[i]<<"\n";
    }

    return 0;
}