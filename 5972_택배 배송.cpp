// 언어 : C++ , (성공/실패) : 1/0 , 메모리 : 5532 KB , 시간 : 24ms
#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h> // memset
#include <queue>

using namespace std;

#define X first
#define Y second

int n,m;

vector<pair<int,int>> adj[50001];
int d[50001];
const int INF = 1e9+10;

int main(void){
    // 입출력 속도 최적화
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    fill(d,d+50001,INF);

    cin>>n>>m;
    while(m--){
        int a,b,c;
        cin>>a>>b>>c;
        adj[a].push_back({c,b});
        adj[b].push_back({c,a});
    }

    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;

    d[1] = 0;
    pq.push({d[1],1});

    while(!pq.empty()){
        auto cur = pq.top(); pq.pop();
        if(d[cur.Y] != cur.X) continue;
        for(auto nxt: adj[cur.Y]){
            if(d[nxt.Y] <= d[cur.Y]+nxt.X) continue;
            d[nxt.Y] = d[cur.Y] + nxt.X;
            pq.push({d[nxt.Y],nxt.Y});
        }
    }

    cout<<d[n]<<'\n';

    return 0;
}