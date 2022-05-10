// 언어 : C++ , (성공/실패) : 1/6 , 메모리 : 2024 KB , 시간 : 0ms
#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h> // memset

using namespace std;

int rm;
int cnt = 0;
vector<int> adj[100];

void dfsd(int x){
    for(int a:adj[x]){
        dfsd(a);
    }
    adj[x].clear();
}

void dfs(int x){
    if(x == rm) return;
    int tmp_cnt = 0;
    for(int a: adj[x]){
        if(a!=rm) {
            dfs(a);
            tmp_cnt++;
        }
    }
    if(!tmp_cnt) cnt++;
}

int main(void){
    // 입출력 속도 최적화
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int N; cin>>N;
    int root;
    for(int i=0;i<N;i++){
        int tmp; cin>>tmp;
        if(tmp==-1) {
            root = i;
            continue;
        }
        adj[tmp].push_back(i);
    }

    cin>>rm;

    dfsd(rm);
    dfs(root);

    cout<<cnt<<'\n';

    return 0;
}