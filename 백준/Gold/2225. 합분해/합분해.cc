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

ll dp[401][201];

ll t_d(ll N, ll K){
    if(K == 1) return 1;
    if(dp[N][K]) return dp[N][K];
    ll cnt = 0;
    for(int i=0; i<=N; i++){
        cnt += t_d(N-i, K-1) % 1000000000;
    }
    return dp[N][K] = cnt % 1000000000;
}

int main(void){
    // 입출력 속도 최적화
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    ll N, K; cin>>N>>K;
    for(int i=0; i<=N; i++){
        dp[i][1] = 1;
    }

    cout<<t_d(N,K);

    return 0;
}