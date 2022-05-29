// 언어 : C++ , (성공/실패) : 1/9 , 메모리 : 2032 KB , 시간 : 0ms
#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h> // memset
#include <math.h>

using namespace std;
typedef long long ll;

int main(void){
    // 입출력 속도 최적화
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    ll N; cin>>N;

     ll st=0,en=sqrt(N);

     // en * en == N이면 그대로 en출력해준다. q^2==N 일 경우에해당.
     if(en*en == N){
         cout<<en<<'\n';
         return 0;
     }

     en++;


     // q^2 > N 일경우
     while(st<en){
         ll mid = (en + st) / (ll)2;
         if(mid * mid > N){
             en = mid;
         }else{
             st = mid + 1;
         }
     }

     cout<<en<<'\n';

    return 0;
}