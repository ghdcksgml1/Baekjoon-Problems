// 언어 : C++ , (성공/실패) : 1/2 , 메모리 : 141928 KB , 시간 : 1516ms
#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h> // memset

using namespace std;

struct Edge{
    int i,j;
    int cnt;
};

vector<Edge> edges;
vector<bool> direction;
vector<int> adj[1000001];

int deg[1000001];
bool visit[1000001];

vector<pair<int,int>> ans;
int aa[1000001];
int bb[1000001];

void addEdge(int a,int b){
    edges.push_back({a,b,1});
    adj[a].push_back(edges.size()-1);
    adj[b].push_back(edges.size()-1);
}

void dfs(int i){
    visit[i] = true;
    while(adj[i].size()){
        int ei = adj[i].back();
        if(edges[ei].cnt){
            edges[ei].cnt--;
            if(ei < direction.size()){
                direction[ei] = (edges[ei].i == i);
            }
            dfs(edges[ei].i + edges[ei].j - i);
        }else{
            adj[i].pop_back();
        }
    }
}

int main(void){
    // 입출력 속도 최적화
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int N,M; cin>>N>>M;
    for(int i=0;i<M;i++){
        int a,b; cin>>a>>b;
        ans.push_back({a,b});
        a--; b--;
        deg[a]++; deg[b]++;
        addEdge(a,b);
        direction.push_back(false);
    }

    vector<int> odds;
    for(int i=0;i<N;i++) if(deg[i]%2) odds.push_back(i);
    for(int i=0;i<odds.size();i+=2) addEdge(odds[i],odds[i+1]);
    for(int i=0;i<N;i++){
        if(!visit[i]){
            dfs(i);
        }
    }


    if(odds.empty()) cout<<0<<'\n';
    else cout<<1<<'\n';
    for(int i=0;i<ans.size();i++){
        if(direction[i]){
            cout<<ans[i].second<<' '<<ans[i].first<<'\n';
        }else{
            cout<<ans[i].first<<' '<<ans[i].second<<'\n';

        }
    }

    return 0;
}