// 언어 : C++ , (성공/실패) : 1/1 , 메모리 : 2172 KB , 시간 : 0ms
#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h> // memset
#define MAX 301

using namespace std;

vector<int> a[MAX][2];
int d[MAX][2];
bool c[MAX][2];

int N,M,K1,K2;
int arr[MAX];


bool dfs(int x,int k){
    for(auto t : a[x][k]){
        if(c[t][k]) continue;
        c[t][k] = true;
        if(d[t][k] == 0 || dfs(d[t][k],k)){
            d[t][k] = x;
            return true;
        }
    }
    return false;
}

int main(void){
    // 입출력 속도 최적화
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin>>N>>M>>K1>>K2;

    int ans1=0, ans2=0;

    while(K1--){
        int tmp1,tmp2; cin>>tmp1>>tmp2;
        a[tmp1][0].push_back(tmp2);
    }

    while(K2--){
        int tmp1,tmp2; cin>>tmp1>>tmp2;
        a[tmp1][1].push_back(tmp2);
    }

    for(int i=1;i<=N;i++){
        memset(c,false,sizeof(c));
        if(dfs(i,0)) ans1++;
        if(dfs(i,1)) ans2++;
    }
    if(ans1 >= ans2) cout<<"그만 알아보자"<<'\n';
    else cout<<"네 다음 힐딱이"<<'\n';
    return 0;
}