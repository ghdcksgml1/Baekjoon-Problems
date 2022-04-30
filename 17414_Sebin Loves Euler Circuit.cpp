// 언어 : C++ , (성공/실패) : 1/0 , 메모리 : 2024 KB , 시간 : 0ms
#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h> // memset

using namespace std;

struct Component{
    vector<int> odd,even;

    int connectOdd(){
        int ret = odd.back();
        odd.pop_back();
        even.push_back(ret);
        return ret;
    }

    int connectEven(){
        int ret = even.back();
        even.pop_back();
        odd.push_back(ret);
        return ret;
    }
};

vector<int> adj[200001];
int deg[200001];
bool visit[200001];
vector<pair<int,int>> ans;

void dfs(Component& comp,int i){
    if(visit[i]) return;
    visit[i] = true;
    if(deg[i]%2) comp.odd.push_back(i);
    else comp.even.push_back(i);
    for(int j : adj[i]) dfs(comp,j);
}

int main(void){
    // 입출력 속도 최적화
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int N,M; cin>>N>>M;
    for(int i=0;i<M;i++){
        int v,e; cin>>v>>e;
        adj[v].push_back(e);
        adj[e].push_back(v);
        deg[v]++; deg[e]++;
    }

    vector<Component> component;
    for(int i=1;i<=N;i++){
        if(!visit[i]){
            Component comp;
            dfs(comp,i);
            component.push_back(comp);
        }
    }

    for(int i=0;i<component.size()-1;i++){
        pair<int,int> tmp;
        if(component[i].odd.size()){
            tmp.first = component[i].connectOdd();
        }else{
            tmp.first = component[i].connectEven();
        }

        if(component[i+1].odd.size()){
            tmp.second = component[i+1].connectOdd();
        }else{
            tmp.second = component[i+1].connectEven();
        }
        ans.push_back(tmp);
    }

    vector<int> odd,even;
    for(auto& comp: component){
        for(int i:comp.odd) odd.push_back(i);
        for(int i:comp.even) even.push_back(i);
    }

    for(int i=0;i<odd.size();i+=2){
        ans.push_back({odd[i],odd[i+1]});
    }

    cout<<ans.size()<<'\n';
    for(auto a : ans){
        cout<<a.first<<' '<<a.second<<'\n';
    }

    return 0;
}