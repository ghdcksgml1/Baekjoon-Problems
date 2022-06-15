// 언어 : C++ , (성공/실패) : 1/0 , 메모리 : 16656 KB , 시간 : 88ms
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string.h> // memset

using namespace std;

int N,M;
vector<int> adj[500001];
int inDegree[1001];
int t[1001];

void topologySort(){
    queue<int> q;
    for(int i=1;i<=N;i++){
        if(inDegree[i] == 0){
            q.push(i);
        }
    }

    for(int i=1;i<=N;i++){
        int cur = q.front(); q.pop();
        for(int a: adj[cur]){
            if(--inDegree[a] == 0){
                q.push(a);
                t[a]+=t[cur];
            }
        }
    }
}

int main(void){
    // 입출력 속도 최적화
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin>>N>>M;
    while(M--){
        int a,b; cin>>a>>b;
        adj[a].push_back(b);
        inDegree[b]++;
    }
    for(int i=1;i<=N;i++) t[i] = 1;
    topologySort();
    for(int i=1;i<=N;i++){
        cout<<t[i]<<' ';
    }

    return 0;
}