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

ll dp[100010][4];

int main(void){
    // 입출력 속도 최적화
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int T; cin>>T;

    while(T--){
        int N; cin>>N;
        memset(dp, 0, sizeof(dp));
        dp[1][1] = 1; dp[2][2] = 1, dp[3][3] = 1;

        for(int i=0; i<=N; i++){
            dp[i+1][1] = max(dp[i+1][1], dp[i][2] + dp[i][3] % 1000000009);
            dp[i+2][2] = max(dp[i+2][2], dp[i][1] + dp[i][3] % 1000000009);
            dp[i+3][3] = max(dp[i+3][3], dp[i][1] + dp[i][2] % 1000000009);
        }

        cout<<(dp[N][1]+dp[N][2]+dp[N][3]) % 1000000009<<"\n";
    }

    return 0;
}