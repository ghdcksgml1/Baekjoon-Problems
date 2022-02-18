// 언어 : C++ , (성공/실패) : 1/1 , 메모리 : 2024 KB , 시간 : 0ms
#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h> // memset

using namespace std;
typedef long long ll;

ll A[5][5];
ll result[5][5];
ll tmp[5][5];
ll N,B;

void pow(ll X[5][5], ll Y[5][5]){
    memset(tmp,0,sizeof(tmp));
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            for(int k=0;k<N;k++){
                tmp[i][j] += (X[i][k]*Y[k][j]);
                tmp[i][j] %= 1000;
            }
        }
    }
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            X[i][j] = tmp[i][j];
        }
    }
}

int main(void){
    // 입출력 속도 최적화
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin>>N>>B;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin>>A[i][j];
        }
        result[i][i] = 1; // 단위 행렬 : 대각선이 모두 1인 행렬
    }

    while(B>0){
        if(B%2 == 1){
            pow(result,A);
        }
        pow(A,A);
        B /= 2;
    }

    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cout<<result[i][j]<<' ';
        }
        cout<<'\n';
    }

    return 0;
}