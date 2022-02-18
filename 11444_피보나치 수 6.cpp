// 언어 : C++ , (성공/실패) : 1/0 , 메모리 : 2024 KB , 시간 : 0ms
#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h> // memset

using namespace std;
typedef long long ll;

ll result[2][2] = {1,0,0,1};
ll A[2][2] = {1,1,1,0};
ll tmp[2][2];

void pow(ll X[2][2], ll Y[2][2]){
    memset(tmp,0,sizeof(tmp));
    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            for(int k=0;k<2;k++){
                tmp[i][j] += (X[i][k]*Y[k][j]);
                tmp[i][j] %= 1000000007;
            }
        }
    }

    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            X[i][j] = tmp[i][j];
        }
    }
}

int main(void){
    // 입출력 속도 최적화
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    ll N;
    cin>>N;

    while(N>0){
        if(N%2 == 1){
            pow(result,A);
        }
        pow(A,A);
        N/=2;
    }

    cout<<result[1][0]<<'\n';

    return 0;
}