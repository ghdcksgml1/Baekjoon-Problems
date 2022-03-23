// 언어 : C++ , (성공/실패) : 1/0 , 메모리 : 2024 KB , 시간 : 0ms
#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h> // memset

using namespace std;
typedef long long ll;

ll dp[1000001];

ll dpp(ll x){
    if(dp[x]!=0) return dp[x];
    return dp[x] = dpp(x-1)+dpp(x-5);
}

int main(void){
    // 입출력 속도 최적화
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int N; cin>>N;
    dp[1]=1,dp[2]=1,dp[3]=1,dp[4]=2,dp[5]=2,dp[6]=3,dp[7]=4,dp[8]=5,dp[9]=7,dp[10]=9;
    while(N--){
        ll tmp; cin>>tmp;
        cout<<dpp(tmp)<<'\n';
    }

    return 0;
}