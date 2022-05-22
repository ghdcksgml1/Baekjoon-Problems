// 언어 : C++ , (성공/실패) : 1/0 , 메모리 : 9848 KB , 시간 : 76ms
#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h> // memset

using namespace std;

int arr[1001][1001];
int dp[1001][1001];

int dx[3] = {-1,0,-1};
int dy[3] = {0,-1,-1};

int main(void){
    // 입출력 속도 최적화
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int N,M; cin>>N>>M;

    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cin>>arr[i][j];
            if(i==0 && j==0) dp[i][j] = arr[i][j];
            for(int cur=0;cur<3;cur++){
                int nx = i + dx[cur];
                int ny = j + dy[cur];
                if(nx<0 || ny<0 || nx>=N || ny>=M) continue;
                dp[i][j] = max(dp[i][j], dp[nx][ny] + arr[i][j]);
            }
        }
    }

    cout<<dp[N-1][M-1]<<'\n';

    return 0;
}