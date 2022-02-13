// 언어 : C++ , (성공/실패) : 1/8 , 메모리 : 5928 KB , 시간 : 44 ms
#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h> // memset

using namespace std;

typedef long long ll;

int mu[1000010];

// mu 구하기
void buildMu(){
    mu[1] = 1;
    for(int i=1;i<=1000000;i++){
        for(int j=2;i*j<=1000000;j++){
            mu[i*j] -= mu[i];
        }
    }
}

ll sqFreeCnt(ll n){
    ll cnt = 0;
    for(ll i=1;i*i<=n;i++){
        cnt += mu[i] * (n/(i*i));
    }
    return cnt;
}

int main(void){
    // 입출력 속도 최적화
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    ll target;
    cin>>target;

    buildMu();
    ll st=0; ll en=2*target;
    while(st < en-1){
        ll mid = (st + en) / 2;
        ll num = sqFreeCnt(mid);
        if(target > num){
            st = mid;
        }else{
            en = mid;
        }
    }
    cout<<en<<'\n';
    return 0;
}