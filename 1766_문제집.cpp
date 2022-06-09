// 언어 : C++ , (성공/실패) : 1/0 , 메모리 : 4088 KB , 시간 : 32ms
#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h> // memset
#include <queue>
#define MAX 32001

using namespace std;

int N,M;
vector<int> adj[MAX];
int inDegree[MAX];
int result[MAX];

void topologySort(){
    priority_queue<int,vector<int>,greater<int>> pq;
    for(int i=1;i<=N;i++){
        if(inDegree[i] == 0){
            pq.push(i);
        }
    }

    for(int i=1;i<=N;i++){
        int cur = pq.top(); pq.pop();
        result[i] = cur;
        for(int x : adj[cur]){
            if(--inDegree[x] == 0){
                pq.push(x);
            }
        }
    }

    for(int i=1;i<=N;i++){
        cout<<result[i]<<' ';
    }
}

int main(void){
    // 입출력 속도 최적화
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin>>N>>M;

    for(int i=1;i<=M;i++){
        int a,b; cin>>a>>b;
        inDegree[b]++;
        adj[a].push_back(b);
    }


    topologySort();

    return 0;
}