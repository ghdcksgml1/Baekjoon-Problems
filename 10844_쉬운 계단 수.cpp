// 언어 : C++ , (성공/실패) : 1/0 , 메모리 : 2028 KB , 시간 : 0ms
#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h> // memset
#define MOD 1000000000

using namespace std;
typedef long long ll;
ll dp[101][10];

int main(void){
    // 입출력 속도 최적화
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    ll N; cin>>N;

    ll result = 0;
    for(int i=1;i<10;i++){
        dp[1][i] = 1;
    }

    for(int i=2;i<=N;i++){
        for(int j=0;j<10;j++){
            if(j==0){
                dp[i][j] = dp[i-1][j+1];
            }else if(j==9){
                dp[i][j] = dp[i-1][j-1];
            }else{
                dp[i][j] = dp[i-1][j-1] + dp[i-1][j+1];
            }
            dp[i][j] %= MOD;
        }
    }

    for(int i=0;i<10;i++){
        result += dp[N][i];
        result %= MOD;
    }

    cout<<result<<'\n';

    return 0;
}