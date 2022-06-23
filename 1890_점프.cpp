// 언어 : C++ , (성공/실패) : 1/0 , 메모리 : 2024 KB , 시간 : 0ms
#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h> // memset

using namespace std;
typedef long long ll;

int N;
ll arr[101][101];
ll dp[101][101];

void solve(int x,int y){
    if(x>N || y>N) return;
    dp[x][y] += 1;
    if(arr[x][y] == 0) return;
    if(x+arr[x][y] <= N) solve(x+arr[x][y],y);
    if(y+arr[x][y] <= N) solve(x,y+arr[x][y]);
}

int main(void){
    // 입출력 속도 최적화
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin>>N;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            cin>>arr[i][j];
        }
    }

    dp[1][1] = 1;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            if(arr[i][j] == 0) continue; // 0이면 건너뛰기
            if(dp[i][j] != 0){
                int val = arr[i][j];
                if(i+val <= N) dp[i+val][j] += dp[i][j];
                if(j+val <= N) dp[i][j+val] += dp[i][j];
            }
        }
    }

    cout<<dp[N][N]<<'\n';

    return 0;
}