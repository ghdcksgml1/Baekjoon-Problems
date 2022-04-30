// 언어 : C++ , (성공/실패) : 1/1 , 메모리 : 20148 KB , 시간 : 140ms
#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h> // memset

using namespace std;

vector<int> adj[200001];
int deg[200001];
bool visit[200001];

void dfs(pair<int,int>& comp,int i){
    if(visit[i]) return;
    visit[i] = true;
    if(deg[i]%2) comp.first++;
    else comp.second++;
    for(int j: adj[i]) dfs(comp,j);
}

void connect(pair<int,int>& comp){
    if(comp.first){
        comp.first--;
        comp.second++;
    }else{
        comp.first++;
        comp.second--;
    }
}


int main(void){
    // 입출력 속도 최적화
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int N,M; cin>>N>>M;
    for(int i=0;i<M;i++){
        int u,v; cin>>u>>v;
        deg[u]++; deg[v]++;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<pair<int,int>> component;
    for(int i=1;i<=N;i++){
        if(!visit[i] && deg[i]>0){
            pair<int,int> comp = {0,0};
            dfs(comp,i);
            component.push_back(comp);
        }
    }

    int cnt=0;
    for(int i=0;i<component.size()-1;i++){
        connect(component[i]);
        connect(component[i+1]);
        cnt++;
    }

    int n = 0;
    for(pair<int,int>& cur: component){
        n += cur.first;
    }

    if(n>=2) cout<<(n-2)/2+cnt+1<<'\n';
    else cout<<cnt+1<<'\n';

    return 0;
}