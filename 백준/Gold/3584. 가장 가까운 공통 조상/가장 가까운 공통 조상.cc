// 언어 : C++ , (성공/실패) : 1/0 , 메모리 : 2024 KB , 시간 : 0ms
#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h> // memset

#define ALL(x) begin(x), end(x)
#define pll pair<ll,ll>
#define pii pair<int,int>
#define xx first
#define yy second
#define MAX 1e6

using namespace std;
typedef long long ll;

vector<int> adj[10001];

int getLevel(int node){

    int level = 0;
    while(!adj[node].empty()){
        level++;
        node = adj[node][0];
    }

    return level;
}

int main(void){
    // 입출력 속도 최적화
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int T; cin>>T;
    while(T--){
        int N; cin>>N;
        for(int i=1; i<=N; i++){
            adj[i].clear();
        }

        for(int i=1;i<N; i++){
            int a,b; cin>>a>>b;
            adj[b].push_back(a);
        }
        int aa,bb; cin>>aa>>bb;

        int l1 = getLevel(aa), l2 = getLevel(bb);
        while(true){
            if(aa == bb) break;
            if(l1>l2){
                l1--;
                aa = adj[aa][0];
            }else{
                l2--;
                bb = adj[bb][0];
            }
        }
        cout<<aa<<'\n';
    }

    return 0;
}