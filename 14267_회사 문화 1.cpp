#include <iostream>
#include <vector>
#include <string.h>

using namespace std;

int n,m;
int n_arr[100001];
int val[100001];
int memo[100001];
vector<int> v[100001];

void dfs(int idx,int value){
    if(memo[idx] != 0) return;
    memo[idx] = value;
    for(int i=0;i<v[idx].size();i++){
        dfs(v[idx][i],value+val[v[idx][i]]);
    }
}

void init(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
}

int main(void){
    init();
    memset(val,0,sizeof(val));
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>n_arr[i];
        if(n_arr[i] == -1) continue;
        v[n_arr[i]].push_back(i); // 직속상관에게 직속부하 정보를 넣음.
    }

    for(int i=0;i<m;i++){
        int n1,n2;
        cin>>n1>>n2;
        val[n1] += n2;
    }
    dfs(1,0);
    for(int i=1;i<=n;i++){
        cout<<memo[i]<<' ';
    }
    return 0;
}