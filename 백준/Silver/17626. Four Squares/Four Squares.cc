// 언어 : C++ , (성공/실패) : 1/0 , 메모리 : 2024 KB , 시간 : 0ms
#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <string.h> // memset

#define ALL(x) begin(x), end(x)
#define pll pair<ll,ll>
#define pii pair<int,int>
#define xx first
#define yy second
#define MAX 1e6

using namespace std;
typedef long long ll;

int dp[200001];


int main(void){
    // 입출력 속도 최적화
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int N; cin>>N;

    memset(dp, -1, sizeof(dp));

    for(int i=0; pow(i,2) <= N; i++){
        dp[i*i] = 1;
    }

    for(int i=1; i<=N; i++){
        if(dp[i] != -1) {
            int tmp_N = N - i;
            int idx = 1;
            vector<int> v;
            while (pow(idx, 2) <= tmp_N) {
                v.push_back(pow(idx++, 2));
            }

            for(int cur : v){
                if(dp[i + cur] == -1) dp[i+cur] = dp[i] + 1;
                else{
                    dp[i+cur] = min(dp[i+cur], dp[i] + 1);
                }
            }
        }
    }

    cout<<dp[N]<<"\n";

    return 0;
}