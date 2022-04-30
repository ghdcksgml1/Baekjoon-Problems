// 언어 : C++ , (성공/실패) : 1/8 , 메모리 : 6404 KB , 시간 : 100ms
#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h> // memset

using namespace std;

vector<int> adj[1001];
int check[1001];
bool visit[1001];

void dfs(pair<int,int>& comp,int i){
    if(visit[i]) return;
    visit[i] = true;
    if(check[i]%2) comp.first++;
    else comp.second++;
    for(int j: adj[i]) dfs(comp,j);
}

void connection(pair<int,int>& comp){
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

    int V,E; cin>>V>>E;
    for(int i=0;i<E;i++){
        int v,e; cin>>v>>e;
        adj[v].push_back(e);
        adj[e].push_back(v);
        check[v] += 1;
        check[e] += 1;
    }

    vector<pair<int,int>> component;
    for(int i=1;i<=V;i++){
        if(!visit[i]){
            pair<int,int> comp = {0,0};
            dfs(comp,i);
            component.push_back(comp);
        }
    }

    int cnt = 0;

    for(int i=0;i<component.size()-1;i++){
        connection(component[i]);
        connection(component[i+1]);
        cnt++;
    }

    int n = 0;
    for(auto& cur : component){
        n += cur.first;
    }

    if(n<=2) cout<<cnt;
    else cout<<(n-2)/2+cnt;

    return 0;
}