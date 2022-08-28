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

vector<int> arr;
int u_dp[1001];
int d_dp[1001];

int main(void){
    // 입출력 속도 최적화
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int N; cin>>N;
    for(int i=0; i<N; i++){
        int tmp; cin>>tmp;
        arr.push_back(tmp);
    }

    u_dp[0] = 1;
    for(int i=1; i<N; i++){
        u_dp[i] = 1;
        for(int j=0; j<i; j++){
            if(arr[j] < arr[i])
                u_dp[i] = max(u_dp[i], u_dp[j] + 1);
        }
    }

    for(int i=N-1; i>=0; i--){
        d_dp[i] = 1;
        for(int j=N-1; j>i; j--){
            if(arr[j] < arr[i])
                d_dp[i] = max(d_dp[i], d_dp[j] + 1);
        }
    }

    int mx = 1;
    for(int i=0; i<N; i++){
        for(int j=i+1; j<N; j++){
            if(arr[i] > arr[j]){
                mx = max(mx, u_dp[i] + d_dp[j]);
            }
        }
    }

    cout<<mx<<"\n";

    return 0;
}