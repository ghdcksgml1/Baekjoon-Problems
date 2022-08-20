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

vector<int> v;
int dp[2001][2001];

int solve(int S,int E){
    if(dp[S][E] != -1) return dp[S][E];
    if(v[S] != v[E]) return dp[S][E] = 0;
    else{
        if(S+1 > E+1) return dp[S][E] = 1;
        return dp[S][E] = solve(S+1, E-1);
    }
}

int main(void){
    // 입출력 속도 최적화
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int N; cin>>N;
    v.push_back(0);
    for(int i=0;i<N;i++){
        int tmp; cin>>tmp;
        v.push_back(tmp);
    }
    memset(dp,-1,sizeof(dp));
    for(int i=0;i<2001;i++){
        dp[i][i] = 1;
    }

    for(int i=1;i<=N;i++){
        for(int j=i;j<=N;j++){
            dp[i][j] = solve(i, j);
        }
    }

    int M; cin>>M;
    while(M--){
        int a,b; cin>>a>>b;
        cout<<dp[a][b]<<'\n';
    }

    return 0;
}