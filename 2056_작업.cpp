// 언어 : C++ , (성공/실패) : 1/2 , 메모리 : 5940 KB , 시간 : 76 ms
#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h> // memset
#include <queue>
#define MAX 10001

using namespace std;

int N;

vector<int> adj[MAX];
int inDegree[MAX];
int t[MAX];
int result[MAX];
int res=0;

void topologySort(){
    queue<int> q;

    for(int i=1;i<=N;i++){
        if(inDegree[i] == 0){
            q.push(i);
            result[i] = t[i];
        }
    }

    for(int i=1;i<=N;i++){
        if(q.empty()){
            cout<<i<<" : Cycle";
            return;
        }
        int cur = q.front(); q.pop();
        for(int x : adj[cur]){
            if(--inDegree[x] == 0){
                q.push(x);
            }
            result[x] = max(result[x], result[cur]+t[x]);
        }
    }

    for(int i=1;i<=N;i++){
        res = max(res,result[i]);
    }
    cout<<res;
}

int main(void){
    // 입출력 속도 최적화
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin>>N;
    for(int i=1;i<=N;i++){
        int tmp; cin>>tmp;
        t[i] = tmp;
        cin>>tmp;
        while(tmp--){
            int tmp2; cin>>tmp2;
            inDegree[i]++;
            adj[tmp2].push_back(i);
        }
    }

    topologySort();

    return 0;
}