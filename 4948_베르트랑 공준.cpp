// 언어 : C++ , (성공/실패) : 1/0 , 메모리 : 6904 KB , 시간 : 4 ms
#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h> // memset

using namespace std;

bool PN[1000001];
int pn_dp[1000001];

void era(){
    for(int i=2;i*i<=1000000;i++){
        if(PN[i]) continue;
        for(int j=2;i*j<=1000000;j++){
            PN[i*j] = true;
        }
    }
}

int main(void){
    // 입출력 속도 최적화
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    era();
    int sum = 0;
    for(int i=1;i<=1000000;i++){
        if(!PN[i]) sum++;
        pn_dp[i] = sum;
    }

    while(true){
        int tmp; cin>>tmp;
        if(tmp == 0) break;
        cout<<pn_dp[tmp*2] - pn_dp[tmp]<<'\n';
    }

    return 0;
}