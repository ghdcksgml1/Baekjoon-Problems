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

vector<pii> v;
int dp[1000];
int main(void){
    // 입출력 속도 최적화
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    memset(dp, 1000000, sizeof(dp));

    int N, M; cin>>N>>M;
    while(M--){
        int a,b; cin>>a>>b;
        v.push_back({a,b});
    }

    dp[0] = 0;
    for(int i=0;i<=N;i++){
        for(pii val : v){
            dp[i+6] = min(dp[i+6], dp[i] + val.first);
            dp[i+1] = min(dp[i+1], dp[i] + val.second);
        }
    }

    int mn = 10000000;
    for(int i=N;i<=N+6;i++){
        mn = min(mn, dp[i]);
    }

    cout<<mn<<'\n';

    return 0;
}