// 언어 : C++ , (성공/실패) : 1/2 , 메모리 : 2440 KB , 시간 : 4ms
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string.h> // memset
#define MAX 501

using namespace std;

int N;
int t[MAX];
vector<int> adj[MAX];
int inDegree[MAX];

int result[MAX];

void topologySort(){
    queue<int> q;
    for(int i=1;i<=N;i++){
        if(inDegree[i] == 0) {
            q.push(i);
            result[i] = t[i];
        }
    }
    while(!q.empty()){
        int cur = q.front(); q.pop();
        for(int x : adj[cur]){
            if(--inDegree[x] == 0) {
                q.push(x);
            }
            result[x] = max(result[x], result[cur] + t[x]);
        }
    }

    for(int i=1;i<=N;i++){
        cout<<result[i]<<'\n';
    }
}

int main(void){
    // 입출력 속도 최적화
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin>>N;

    for(int i=1;i<=N;i++){
        cin>>t[i];
        while(true){
            int tmp; cin>>tmp;
            if(tmp == -1) break;
            adj[tmp].push_back(i);
            inDegree[i]++;
        }
    }

    topologySort();

    return 0;
}