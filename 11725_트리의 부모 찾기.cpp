// 언어 : C++ , (성공/실패) : 1/1 , 메모리 : 10156 KB , 시간 : 44ms
#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h> // memset

using namespace std;

vector<int> adj[100001];
int root[100001];
bool visited[100001];

void dfs(int x){
    for(int a : adj[x]){
        if(!visited[a]){
            root[a] = x;
            visited[a] = true;
            dfs(a);
        }
    }
    return ;
}

int main(void){
    // 입출력 속도 최적화
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int N; cin>>N;
    for(int i=0;i<N-1;i++){
        int a,b; cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(1);
    for(int i=2;i<=N;i++){
        cout<<root[i]<<'\n';
    }

    return 0;
}