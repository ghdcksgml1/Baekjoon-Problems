// 언어 : C++ , (성공/실패) : 1/0 , 메모리 : 4752 KB , 시간 : 36ms
#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h> // memset
#include <queue>

using namespace std;
#define X first
#define Y second

int n,m;
int A,B;
vector<pair<int,int>> adj[1001];
int d[1001];
int pre[1001];
const int INF = 1e9+10;

vector<int> result;

int main(void){
    // 입출력 속도 최적화
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    fill(d,d+1001,INF);

    cin>>n>>m;
    while(m--){
        int u,v,e;
        cin>>u>>v>>e;
        adj[u].push_back({e,v});
    }

    cin>>A>>B;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    d[A] = 0;
    pq.push({d[A],A});

    while(!pq.empty()){
        auto cur = pq.top(); pq.pop();
        if(d[cur.Y] != cur.X) continue;
        for(auto nxt: adj[cur.Y]){
            if(d[nxt.Y] <= d[cur.Y]+nxt.X) continue;
            d[nxt.Y] = d[cur.Y]+nxt.X;
            pre[nxt.Y] = cur.Y;
            pq.push({d[nxt.Y],nxt.Y});
        }
    }

    cout<<d[B]<<'\n';
    int tmp = pre[B];
    result.push_back(B);
    while(tmp != 0){
        result.push_back(tmp);
        tmp = pre[tmp];
    }

    reverse(result.begin(), result.end());
    cout<<result.size()<<'\n';
    for(int i: result){
        cout<<i<<' ';
    }

//    for(int i=1;i<=n;i++){
//        cout<<i<<": "<<d[i]<<" , "<<pre[i]<<'\n';
//    }

    return 0;
}